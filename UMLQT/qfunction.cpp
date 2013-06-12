#include "qfunction.h"
#include <QRegExp>

QFunction::QFunction(umlFunction* func, QObject *parent):QObject(parent),function(func),correct(true)
{
	tmpName = QString::fromStdString(function->getFancyString());
}

QString QFunction::getName() const
{
	return tmpName;//QString::fromStdString(function->getString());
}

void QFunction::setName(const QString &name)
{

	if(tmpName == name) return;
	tmpName = name;
	emit nameChanged();

}

void QFunction::commit()
{
		string old = function->getFancyString();
		if (tmpName == QString::fromStdString(old))
		{
			correct=true;
			emit correctChanged();
			return;
		}

		if(!parse(tmpName))return;
		string str = function->getFancyString();
		if(tmpName.toStdString() != str)
		{
			tmpName = QString::fromStdString(str);
			emit nameChanged();
		}
}


bool QFunction::parse(const QString &str)
{
	list<pair<string,string>> attributes;
	QString retType,name,access;
	QRegExp reg("\\s*([#\\+\\-])?\\s*\\s*([A-Za-z_]\\w*|)\\s+([A-Za-z_]\\w*)\\s*\\((.*)\\)");
	if(reg.exactMatch(str))
	{
		access = reg.cap(1);
		retType = reg.cap(2);
		name = reg.cap(3);
		QString params = reg.cap(4);
		if(!params.isEmpty())
		{
			QRegExp pars("(([A-Za-z_]\\w*)\\s+([A-Za-z_]\\w*)\\s*)(,\\s*([A-Za-z_]\\w*)\\s+([A-Za-z_]\\w*)\\s*)*");
			if(pars.exactMatch(params))
			{
				attributes.push_back(pair<string,string>(pars.cap(2).toStdString(),pars.cap(3).toStdString()));
				int pos = pars.cap(1).length();
				QRegExp nextPars(",\\s*([A-Za-z_]\\w*)\\s+([A-Za-z_]\\w*)\\s*");
				while(nextPars.indexIn(params,pos)!=-1)
				{
					attributes.push_back(pair<string,string>
										 (nextPars.cap(1).toStdString(),nextPars.cap(2).toStdString()));
					pos += nextPars.matchedLength();
				}

			}
			else
			{
				//if(correct==true)
				{
					correct = false;
					emit correctChanged();

				}
				return false;
			}
		}
	}
	else
	{
		//if(correct==true)
		{
			correct = false;
			emit correctChanged();

		}
		return false;
	}
		if(access.isEmpty())
			function->setAccessability(accessability::default_);
		else
		{
			function->setAccessability(getBySymbol(access[0].toLatin1()));
		}
		function->setName(name.toStdString());
		function->setType(umlType::getByString(retType.toStdString()));
		list<umlAttribute*>& realParams = function->getParams();
		int diff = realParams.size() - attributes.size();
		if(diff<0)
		{
			for(;diff<0;diff++)
				realParams.push_back(new umlAttribute());
		}
		else if(diff>0)
		{
			auto it = realParams.begin();
			std::advance(it,attributes.size());
			realParams.erase(it,realParams.end());
		}
		auto  itReal = realParams.begin();
		auto itNew = attributes.begin();
		for(;itReal!=realParams.end(),itNew!=attributes.end();itReal++,itNew++)
		{
			string& type = itNew->first;
			umlAttribute* attr = *itReal;
			attr->setName(itNew->second);
			attr->setType(umlType::getByString(type));
		}
		//if(correct==false)
		{
			correct = true;
			emit correctChanged();

		}
		return true;
}




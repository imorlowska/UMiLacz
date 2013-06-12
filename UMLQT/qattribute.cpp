#include "qattribute.h"
#include <QRegExp>
QAttribute::QAttribute(umlAttribute* attribute, QObject *parent):QObject(parent),attribute(attribute)
{
	tmpString = QString::fromStdString(attribute->getString());
}

QString QAttribute::getName() const
{
	return tmpString;//QString::fromStdString(attribute->getString());
}

void QAttribute::setName(const QString &name)
{
	//if (name == QString::fromStdString(attribute->getString()))return;
	if(name == tmpString)
		return;
	tmpString = name;
	emit nameChanged();

}

void QAttribute::commit()
{
	string old = attribute->getString();
	if (tmpString == QString::fromStdString(old))
	{
		correct=true;
		emit correctChanged();
		return;
	}

	if(!parse(tmpString))return;
	string str = attribute->getString();
	if(tmpString.toStdString() != str)
	{
		tmpString = QString::fromStdString(str);
		emit nameChanged();
	}
}


bool QAttribute::parse(const QString &str)
{
	QRegExp regex("\\s*([A-Za-z_]\\w*)\\s+([A-Za-z_]\\w*)\\s*");
	if(!regex.exactMatch(str))
	{
		correct=false;
		emit correctChanged();
		return false;
	}
	string name = regex.cap(2).toStdString(),type = regex.cap(1).toStdString();
	attribute->setName(name);
	attribute->setType(umlType::getByString(type));
	correct=true;
	emit correctChanged();
	return true;

}



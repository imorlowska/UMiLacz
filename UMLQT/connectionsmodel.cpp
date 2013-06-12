#include "connectionsmodel.h"


ConnectionsModel::ConnectionsModel
	(const list<tuple<umlClass *, umlClass *, connectionType, connectionNumber> > &connections,
	 const ClassesModel& classes,
	 QObject *parent):QObjectListModel(new QObjectList(),parent)
{
	for(auto it = connections.begin();it!=connections.end();it++)
	{
		umlClass* c1 = std::get<0>(*it),*c2 = std::get<1>(*it);
		auto it1 = find_if(classes.objectList().begin(),
						   classes.objectList().end(),
						   [c1](QObject* qclass)
							{
									return ((QClass*)qclass)->getClass() == c1;
							});
		if(it1 == classes.objectList().end())
			continue;
		QClass* qc1 = (QClass*)*it1;
		auto it2 = find_if(classes.objectList().begin(),
						   classes.objectList().end(),
						   [c2](QObject* qclass)
							{
									return ((QClass*)qclass)->getClass() == c2;
							});
		if(it2 == classes.objectList().end())
			continue;
		QClass* qc2 = (QClass*)*it2;
		m_objects->append(
					new QConnection(qc1,
									qc2,
									std::get<2>(*it),
									std::get<3>(*it)));

	}
}

//ConnectionsModel::ConnectionsModel(QObject *parent)
//	:QObjectListModel(parent)
//{
//}

void ConnectionsModel::
getConnections(list<tuple<umlClass *, umlClass *,
		connectionType, connectionNumber> >& conn)
{
	conn.clear();
	for(auto it = m_objects->begin();it!=m_objects->end();it++)
	{
		QConnection* qconn = (QConnection*)*it;
		umlClass* c1 = qconn->getQClass1()->getClass(),
				*c2 = qconn->getQClass2()->getClass();
		connectionType ct = qconn->getTypeOrig();
		connectionNumber cn = qconn->getNumberOrig();
		conn.push_back
				(tuple<umlClass*,umlClass*,connectionType,connectionNumber>
						 (c1,
						  c2,
						  ct,
						  cn));
	}
}

QString ConnectionsModel::addConnection(const QVariant &c1, const QVariant &c2,int type,int number)
{
	QClass * class1 = c1.value<QClass*>(),*class2 = c2.value<QClass*>();
	if(type == connectionType::extends_ || type == connectionType::implements_)
	{
		for(auto it = m_objects->begin();it!=m_objects->end();it++)
		{
			QConnection* existing = (QConnection*)*it;
			if((existing->getClass1() == c1 && existing->getClass2() == c2)||
					(existing->getClass1() == c2 && existing->getClass2()==c1))
				return "Inheritance already defined for given classes!";
		}
	}

	if(type == connectionType::contains_)
	{
		for(auto it = m_objects->begin();it!=m_objects->end();it++)
		{
			QConnection* existing = (QConnection*)*it;
			if(((existing->getClass1() == c1 && existing->getClass2() == c2)||
					(existing->getClass1() == c2 && existing->getClass2()==c1))
					&& (existing->getTypeOrig()==connectionType::contains_ ||
						existing->getTypeOrig()==connectionType::other_))
				return "Composition is already defined!\n Use 0..* to 0..* if you want many to many relations";
		}
	}
	append(new QConnection(class1,
						   class2,
						(connectionType)type,
						(connectionNumber)number));
	return QString("");
}

void ConnectionsModel::deleteConnection(const QVariant &conn)
{
	QConnection* connection = conn.value<QConnection*>();
	for(int i=0;i<count();i++)
	{
		if(at(i) == connection)
		{
			remove(i);
			return;
		}
	}
}

void ConnectionsModel::removeClassConnections(QClass *cl)
{
	for(int i=0;i<count();i++)
	{
		if(((QConnection*)at(i))->getQClass1() == cl
				|| ((QConnection*)at(i))->getQClass2()==cl)
		{
			remove(i);
		}
	}
}



/*void ConnectionsModel::populate(const map<pair<QClass *, QClass *>,
								pair<connectionType,connectionNumber> >
								&connections)
{
	for(auto it = connections.begin();it!=connections.end();it++)
	{
		m_objects->append(
					new QConnection(it->first.first,
									it->first.second,
									it->second.first,
									it->second.second));
	}
}*/

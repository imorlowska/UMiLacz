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

list<tuple<umlClass *, umlClass *, connectionType, connectionNumber> > ConnectionsModel::getConnections()
{
	return list<tuple<umlClass*,umlClass*,connectionType,connectionNumber>>();
}

void ConnectionsModel::addConnection(const QVariant &c1, const QVariant &c2,int type,int number)
{
	m_objects->append(
				new QConnection(c1.value<QClass*>(),
								c2.value<QClass*>(),
								(connectionType)type,
								(connectionNumber)number));
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

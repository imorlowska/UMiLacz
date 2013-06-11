#include "connectionsmodel.h"


ConnectionsModel::ConnectionsModel
	(const map<pair<QClass *, QClass *>,
	 pair<connectionType,connectionNumber> > &connections,
	 const ClassesModel& classes,
	 QObject *parent):QObject(parent)
{
	for(auto it = connections.begin();it!=connections.end();it++)
	{
		umlClass* c1 = it->first.first,*c2 = it->first.second;
		auto it1 = find_if(classes.objectList().begin(),
						   classes.objectList().end(),
						   [c1](QClass* qclass)
							{
									return qclass->getClass() == c1;
							});
		if(it1 == classes.objectList().end())
			continue;
		QClass* qc1 = *it1;
		auto it2 = find_if(classes.objectList().begin(),
						   classes.objectList().end(),
						   [c2](QClass* qclass)
							{
									return qclass->getClass() == c2;
							});
		if(it2 == classes.objectList().end())
			continue;
		m_objects->append(
					new QConnection(qc1,
									qc2,
									it->second.first,
									it->second.second));

	}
}

ConnectionsModel::ConnectionsModel(QObject *parent)
	:QObject(parent)
{
}

map<pair<QClass *, QClass *>, pair<connectionType,connectionNumber> > ConnectionsModel::getConnections()
{
	return map<pair<QClass *, QClass *>, pair<connectionType,connectionNumber> >();
}

void ConnectionsModel::addConnection(const QVariant &c1, const QVariant &c2,int type,int number)
{
	m_objects->append(
				new QConnection(QVariant::qvariant_cast<QClass*>(c1),
								QVariant::qvariant_cast<QClass*>(c2),
								type,
								number);
}


void ConnectionsModel::populate(const map<pair<QClass *, QClass *>,
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
}

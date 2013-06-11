#ifndef CONNECTIONSMODEL_H
#define CONNECTIONSMODEL_H

#include "qobjectlistmodel.h"
#include "classesmodel.h"
#include "qconnection.h"
#include <map>
using namespace std;

class ConnectionsModel:QObjectListModel
{
public:
	ConnectionsModel(const map<pair<umlClass*,umlClass*>,
					 pair<connectionType,connectionNumber>>&
					 connections,
					 const ClassesModel& classes,
					 QObject* parent=0);
	ConnectionsModel(QObject *parent=0);

	map<pair<QClass *, QClass *>, pair<connectionType,connectionNumber>> getConnections();

	Q_INVOKABLE
	void addConnection(const QVariant& c1, const QVariant& c2, int type, int number);
private:

};

#endif // CONNECTIONSMODEL_H

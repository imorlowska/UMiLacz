#ifndef CONNECTIONSMODEL_H
#define CONNECTIONSMODEL_H

#include "qobjectlistmodel.h"
#include "classesmodel.h"
#include "qconnection.h"
#include <list>
#include <tuple>
using namespace std;

class ConnectionsModel:public QObjectListModel
{
	Q_OBJECT
public:
	ConnectionsModel
		(const list<tuple<umlClass *, umlClass *, connectionType, connectionNumber> > &connections,
		 const ClassesModel& classes,
		 QObject *parent=0);
	//ConnectionsModel(QObject *parent=0);

	list<tuple<umlClass*,umlClass*,connectionType,connectionNumber>>
	getConnections();

	Q_INVOKABLE
	QString addConnection(const QVariant& c1, const QVariant& c2, int type, int number);

	Q_INVOKABLE
	void deleteConnection(const QVariant& conn);
	virtual ~ConnectionsModel(){}
signals:

public slots:

};

#endif // CONNECTIONSMODEL_H

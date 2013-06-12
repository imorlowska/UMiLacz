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


	void getConnections(list<tuple<umlClass*,umlClass*,connectionType,connectionNumber>>& conn);

	Q_INVOKABLE
	QString addConnection(const QVariant& c1, const QVariant& c2, int type, int number);

	Q_INVOKABLE
	void deleteConnection(const QVariant& conn);

	void removeClassConnections(QClass* cl);
	virtual ~ConnectionsModel(){}
signals:

public slots:

};

#endif // CONNECTIONSMODEL_H

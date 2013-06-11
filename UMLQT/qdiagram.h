#ifndef QDIAGRAM_H
#define QDIAGRAM_H

#include "../umlDiagram.h"
#include "classesmodel.h"
#include "connectionsmodel.h"

class QDiagram:public QObject
{
	Q_OBJECT
	Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
	Q_PROPERTY(ClassesModel* classes READ getClasses)
	Q_PROPERTY(ConnectionsModel* connections READ getConnections)
	//Q_PROPERTY(AttributesModel attributes READ getAttributes)
private:
	umlDiagram* myDiagram;
	ClassesModel classes;
	ConnectionsModel connections;


public:
	QDiagram(umlDiagram* Diagram,QObject* parent=0);
	QString getName()const;
	void setName(const QString& n);

	ClassesModel*  getClasses(){return &classes;}
	ConnectionsModel* getConnections(){return &connections;}
	umlDiagram* getDiagram(){return myDiagram;}

	void commitChanges();

	Q_INVOKABLE
	void addEmptyClass()
	{
		classes.addEmpty();
	}

signals:
	void nameChanged();

};
#endif // QDIAGRAM_H

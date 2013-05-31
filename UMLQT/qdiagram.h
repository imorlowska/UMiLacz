#ifndef QDIAGRAM_H
#define QDIAGRAM_H

#include "../umlDiagram.h"
#include "classesmodel.h"

class QDiagram:public QObject
{
	Q_OBJECT
	Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
	Q_PROPERTY(QVariant classes READ getClasses)
	//Q_PROPERTY(AttributesModel attributes READ getAttributes)
private:
	umlDiagram* myDiagram;
	ClassesModel classes;
public:
	QDiagram(umlDiagram* Diagram,QObject* parent=0);
	QString getName()const;
	void setName(const QString& n);

	QVariant  getClasses(){return QVariant::fromValue(&classes);}

	umlDiagram* getDiagram(){return myDiagram;}

	Q_INVOKABLE
	void addEmptyClass()
	{
		classes.addEmpty();
	}

signals:
	void nameChanged();

};
#endif // QDIAGRAM_H

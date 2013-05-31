#include "qdiagram.h"



QDiagram::QDiagram(umlDiagram *Diagram, QObject *parent):
	QObject(parent),
	myDiagram(Diagram),
	classes(Diagram->getClasses())
{
}

QString QDiagram::getName() const
{
	return QString::fromStdString(myDiagram->getName());
}

void QDiagram::setName(const QString &n)
{
	if(n==getName())return;
	myDiagram->setName(n.toStdString());
	emit nameChanged();
}

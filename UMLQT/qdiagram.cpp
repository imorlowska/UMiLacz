#include "qdiagram.h"



QDiagram::QDiagram(umlDiagram *Diagram, QObject *parent):
	QObject(parent),
	myDiagram(Diagram),
	classes(Diagram->getClasses()),
	connections(Diagram->getDependencies(),classes)
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

void QDiagram::commitChanges()
{
	for(int i=0,s = classes.size();i<s;i++)
	{
		((QClass*)classes.at(i))->commitChanges();
	}
	myDiagram->getClasses().clear();
	auto newClasses = classes.getClasses();
	myDiagram->getClasses().
			insert(myDiagram->getClasses().begin(),
				   newClasses.begin(),newClasses.end());

	auto newDependencies = connections.getConnections();
	myDiagram->getDependencies().clear();
	myDiagram->getDependencies().insert(newDependencies.begin(),
										newDependencies.end());
}

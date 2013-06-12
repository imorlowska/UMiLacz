#include "qdiagram.h"
#include <tuple>
using namespace std;
#include "../converter.h"
#include "../converter2cpp.h"
#include"../converter2java.h"

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

	connections.getConnections(myDiagram->getDependencies());

//	myDiagram->getDependencies().insert(myDiagram->getDependencies().begin(),
//										newDependencies.begin(),
	//										newDependencies.end());
}

void QDiagram::removeClass(const QVariant &cl)
{
	QClass* class_ = cl.value<QClass*>();
	connections.removeClassConnections(class_);
	classes.removeClass(class_);
}

void QDiagram::UMiLCpp()
{
	commitChanges();
	converter2cpp* cpp = new converter2cpp();
		cpp->convert(myDiagram);
}

void QDiagram::UMiLJava()
{
	commitChanges();
	converter2java* java = new converter2java();
	java->convert(myDiagram);
}

#include "qdiagram.h"
#include <tuple>
using namespace std;


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

	list<tuple<umlClass*,umlClass*,connectionType,connectionNumber>>
			newDependencies = connections.getConnections();
	myDiagram->getDependencies().clear();
	for(auto it=newDependencies.begin();it!=newDependencies.end();it++)
	{
		umlClass* c1 = get<0>(*it),*c2 = get<1>(*it);
		connectionType ct = get<2>(*it);
		connectionNumber cn = get<3>(*it);
		myDiagram->getDependencies().
				push_back(
					tuple<umlClass*,umlClass*,connectionType,connectionNumber>(
						get<0>(*it),
						get<1>(*it),
						get<2>(*it),
						get<3>(*it)
						));
	}
//	myDiagram->getDependencies().insert(myDiagram->getDependencies().begin(),
//										newDependencies.begin(),
//										newDependencies.end());
}

void QDiagram::UMiL()
{
	commitChanges();
	//TODO: tutaj mozna wywołac jakas metode do konwertacji
}

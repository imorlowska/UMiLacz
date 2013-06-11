#include "qclass.h"

QClass::QClass(umlClass* Class,QObject* parent)
	:QObject(parent),myClass(Class),
	 functions(Class->getFunctions()),
	 attributes(Class->getAttributes())
{

}


QString QClass::getName()const
{
	return QString::fromStdString(myClass->getName());
}

void QClass::setName(const QString& n)
{
	if(n==getName())return;
	myClass->setName(n.toStdString());
	emit nameChanged();
}

void QClass::commitChanges()
{
	myClass->getAttributes().clear();
	auto newAttributes = attributes.getAttributes();
	myClass->getAttributes().insert(myClass->getAttributes().begin(),newAttributes.begin(),newAttributes.end());


	myClass->getFunctions().clear();
	auto newFunctions = functions.getFunctions();
	myClass->getFunctions().insert(myClass->getFunctions().begin(),newFunctions.begin(),newFunctions.end());


}

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

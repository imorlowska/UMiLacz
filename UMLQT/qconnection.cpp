#include "qconnection.h"

QConnection::QConnection(QClass *c1, QClass *c2, connectionType ct, connectionNumber cn, QObject *parent)
	:class1(c1),class2(c2),number(cn),type(ct),QObject(parent)
{
}



int QConnection::getType()
{
	return type;
}

void QConnection::setType(int type)
{
	if(type == this->type)return;
	this->type = type;
	emit typeChanged();
}

int QConnection::getNumber()
{
	return number;
}

void QConnection::setNumber(int number)
{
	if(number == this->number)return;
	this->number = number;
	emit numberChanged();
}

QVariant QConnection::getClass1()
{
	return QVariant::fromValue(class1);
}

void QConnection::setClass1(const QVariant &c1)
{
	QClass* qc1 = QVariant::qvariant_cast<QClass*>(c1);
	if(qc1 == class1)return;
	class1 = qc1;
	emit class1Changed();
}

QVariant QConnection::getClass2()
{
	return QVariant::fromValue(class2);
}

void QConnection::setClass2(const QVariant &c2)
{
	QClass* qc2 = QVariant::qvariant_cast<QClass*>(c2);
	if(qc2== class1)return;
	class2 = qc2;
	emit class2Changed();
}





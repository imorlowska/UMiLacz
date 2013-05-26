#include "qattribute.h"

QAttribute::QAttribute(umlAttribute* attribute, QObject *parent):QObject(parent),attribute(attribute)
{
}

QString QAttribute::getName() const
{
	return QString::fromStdString(attribute->getString());
}

void QAttribute::setName(const QString &name)
{
	if (name == QString::fromStdString(attribute->getString()))return;
	attribute->setName("parsed:"+name.toStdString());

	emit nameChanged();

}




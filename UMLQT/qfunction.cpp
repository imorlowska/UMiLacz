#include "qfunction.h"

QFunction::QFunction(umlFunction* func, QObject *parent):QObject(parent),function(func)
{
}

QString QFunction::getName() const
{
	return QString::fromStdString(function->getString());
}

void QFunction::setName(const QString &name)
{
	if (name == QString::fromStdString(function->getString()))return;
	function->setName("parsed:"+name.toStdString());

	emit nameChanged();

}




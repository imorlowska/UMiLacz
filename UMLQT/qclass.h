#ifndef QCLASS_H
#define QCLASS_H

#include <QObject>
#include <QList>

#include "functionsmodel.h"
#include "attributesmodel.h"
#include "../umlClass.h"


class QClass:public QObject
{
	Q_OBJECT
	Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
	Q_PROPERTY(FunctionsModel* functions READ getFunctions)
	Q_PROPERTY(AttributesModel* attributes READ getAttributes)
private:
	umlClass* myClass;
	FunctionsModel functions;
	AttributesModel attributes;
public:
	QClass(umlClass* Class,QObject* parent=0);
	QString getName()const;
	void setName(const QString& n);

	FunctionsModel*  getFunctions(){return &functions;}
	AttributesModel*  getAttributes(){return &attributes;}

	umlClass* getClass(){return myClass;}


signals:
	void nameChanged();

};



#endif // QCLASS_H

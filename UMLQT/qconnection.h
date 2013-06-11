#ifndef QCONNECTION_H
#define QCONNECTION_H

#include  "../umlClass.h"
#include "../typedefs.h"
#include "qclass.h"

class QConnection:public QObject
{
	Q_OBJECT
	Q_PROPERTY(int type READ getType WRITE setType NOTIFY typeChanged)
	Q_PROPERTY(int number READ getNumber WRITE setNumber NOTIFY numberChanged)
	Q_PROPERTY(QVariant class1 READ getClass1 WRITE setClass1 NOTIFY class1Changed)
	Q_PROPERTY(QVariant class2 READ getClass2 WRITE setClass2 NOTIFY class2Changed)
	Q_PROPERTY(int id READ getId NOTIFY idChanged)
public:
	QConnection(QClass *c1,QClass *c2,connectionType ct,connectionNumber cn,QObject *parent=0);

	int getType();
	void setType(int type);
	int getNumber();
	void setNumber(int number);

	QVariant getClass1();
	void setClass1(const QVariant& c1);
	QVariant getClass2();
	void setClass2(const QVariant& c2);

	int getId(){return (int)this;}
signals:
	void typeChanged();
	void numberChanged();
	void class1Changed();
	void class2Changed();
	void idChanged();
private:
	//Q_DISABLE_COPY(QConnection)
	QClass *class1,*class2;
	connectionType type;
	connectionNumber number;

};

#endif // QCONNECTION_H

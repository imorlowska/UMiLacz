#ifndef CLASSESMODEL_H
#define CLASSESMODEL_H

#include "qobjectlistmodel.h"
#include "qclass.h"
#include <QVariant>

#include <list>
using namespace std;

class ClassesModel:public QObjectListModel
{
	Q_OBJECT
public:
	ClassesModel(const list<umlClass *> &listOfClasses, QObject *parent=0);
	Q_INVOKABLE void addEmpty();
	void removeClass(QClass* cl);
	list<umlClass*> getClasses();
	virtual ~ClassesModel(){}
};

#endif // CLASSESMODEL_H

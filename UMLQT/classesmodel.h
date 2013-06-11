#ifndef CLASSESMODEL_H
#define CLASSESMODEL_H

#include "qobjectlistmodel.h"
#include "qclass.h"

#include <list>
using namespace std;

class ClassesModel:public QObjectListModel
{
public:
	ClassesModel(const list<umlClass*>& listOfClasses,QObject *parent=0);
	Q_INVOKABLE void addEmpty();
	list<umlClass*> getClasses();
};

#endif // CLASSESMODEL_H

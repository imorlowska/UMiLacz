#ifndef FUNCTIONSMODEL_H
#define FUNCTIONSMODEL_H

#include <qobjectlistmodel.h>
#include <list>
#include "qfunction.h"
using namespace std;

class FunctionsModel : public QObjectListModel
{
	Q_OBJECT
public:
	FunctionsModel(const list<umlFunction*>& l,QObject *parent=0);
	Q_INVOKABLE void addEmpty();
	list<umlFunction*> getFunctions();

signals:
	
public slots:
	
};

#endif // FUNCTIONSMODEL_H

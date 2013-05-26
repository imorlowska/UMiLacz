#ifndef ATTRIBUTESMODEL_H
#define ATTRIBUTESMODEL_H

#include "../umlAttribute.h"
#include "qobjectlistmodel.h"
#include <qattribute.h>

class AttributesModel:public QObjectListModel
{
	Q_OBJECT
public:
	AttributesModel(const list<umlAttribute*>& l,QObject *parent=0);
	Q_INVOKABLE void addEmpty();
	list<umlAttribute*> getAttributes();
};
#endif // ATTRIBUTESMODEL_H

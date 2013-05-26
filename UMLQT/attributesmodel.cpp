#include "attributesmodel.h"


AttributesModel::AttributesModel(const list<umlAttribute*> &listOfFunctions, QObject *parent)
	:QObjectListModel(new QObjectList(),parent)
{
	for(auto it = listOfFunctions.begin();it!=listOfFunctions.end();it++)
		m_objects->append(new QAttribute(*it));
}

void AttributesModel::addEmpty()
{
	//m_objects->append(new QAttribute(new umlAttribute()));
	append(new QAttribute(new umlAttribute()));
}

list<umlAttribute *> AttributesModel::getAttributes()
{
	list<umlAttribute *> attributes;
	for(auto it=m_objects->begin();it!=m_objects->end();it++)
	{
		attributes.push_back(((QAttribute*)*it)->getAttribute());
	}
	return attributes;
}

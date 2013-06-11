#include "classesmodel.h"

ClassesModel::ClassesModel(const list<umlClass *> &listOfClasses, QObject *parent)
	:QObjectListModel(new QObjectList(),parent)
{
	for(auto it = listOfClasses.begin();it!=listOfClasses.end();it++)
		m_objects->append(new QClass(*it));
}

void ClassesModel::addEmpty()
{
	append(new QClass((new umlClass())->setName("bar")));
}

list<umlClass *> ClassesModel::getClasses()
{
	list<umlClass *> classes;
	for(auto it=m_objects->begin();it!=m_objects->end();it++)
	{
		classes.push_back(((QClass*)*it)->getClass());
	}
	return std::move(classes);
}





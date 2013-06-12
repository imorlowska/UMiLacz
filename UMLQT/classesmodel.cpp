#include "classesmodel.h"

ClassesModel::ClassesModel(const list<umlClass *> &listOfClasses, QObject *parent)
	:QObjectListModel(new QObjectList(),parent)
{
	for(auto it = listOfClasses.begin();it!=listOfClasses.end();it++)
		m_objects->append(new QClass(*it));
}

void ClassesModel::addEmpty()
{
	append(new QClass((new umlClass())->setName("bar")->setAccessability(public_)));
}

void ClassesModel::removeClass(QClass *cl)
{
	for(int i=0;i<count();i++)
	{
		if(at(i) == cl)
		{
			remove(i);
			return;
		}
	}
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





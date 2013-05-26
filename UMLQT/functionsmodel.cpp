#include "functionsmodel.h"



FunctionsModel::FunctionsModel(const list<umlFunction*> &listOfFunctions, QObject *parent)
	:QObjectListModel(new QObjectList(),parent)
{
	for(auto it = listOfFunctions.begin();it!=listOfFunctions.end();it++)
		m_objects->append(new QFunction(*it));
}

void FunctionsModel::addEmpty()
{
	//m_objects->append(new QFunction(new umlFunction()));
	append(new QFunction(new umlFunction()));
}

list<umlFunction *> FunctionsModel::getFunctions()
{
	list<umlFunction *> functions;
	for(auto it=m_objects->begin();it!=m_objects->end();it++)
	{
		functions.push_back(((QFunction*)*it)->getFunction());
	}
	return functions;
}

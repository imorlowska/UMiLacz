#include "umlFunction.h"

umlFunction::umlFunction():type(nullptr)
{
    name = "foo";
    accessability_ = none_;
}
umlFunction* umlFunction::setName(string n)
{
    name = n;
    return this;
}
umlFunction* umlFunction::setAccessability(accessability a)
{
    accessability_ = a;
    return this;
}
umlFunction* umlFunction::setType(umlType* t)
{
    type = t;
    return this;
}
umlFunction* umlFunction::addSpecialType(specialType s)
{
    sType.push_back(s);
    return this;
}
umlFunction* umlFunction::removeSpecialType(specialType s)
{
    sType.remove(s);
    return this;
}
umlFunction* umlFunction::addParam(umlAttribute* p)
{
    params.push_back(p);
    return this;
}
umlFunction* umlFunction::removeParam(umlAttribute* p)
{
    params.remove(p);
    return this;
}

string umlFunction::getName()
{
    return name;
}
accessability umlFunction::getAccessability()
{
    return accessability_;
}
umlType* umlFunction::getType()
{
    return type;
}
list<specialType> umlFunction::getSpecialType()
{
    return sType;
}
list<umlAttribute*> umlFunction::getParams()
{
    return params;
}
string umlFunction::getString()
{
    string spec;
    for (list<specialType>::iterator it = sType.begin();
            it != sType.end(); ++it)
    {
        spec += getStringT(*it);
    }
    string param;
    for (list<umlAttribute*>::iterator it = params.begin();
            it != params.end(); ++it)
    {
        param += (*it)->getString() + ", ";
    }
    if(param.length()>2)
    {
        param.pop_back();
        param.pop_back();
    }
    param = "(" + param + ")";

	string typeString;
	if(type==nullptr)
	{
		typeString="void";
	}
	else
	{
		typeString=type->getString();
	}
	return getStringT(accessability_) +" " + spec +" "+ typeString + " "
                    + name + param;
}

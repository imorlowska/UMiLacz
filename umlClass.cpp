#include "umlClass.h"

umlClass::umlClass()
{
    name = "sampleClass";
    accessability_ = none_;
}

umlClass* umlClass::setName(const string &n)
{
    name = n;
    return this;
}
umlClass* umlClass::setAccessability(accessability a)
{
    accessability_ = a;
    return this;
}
umlClass* umlClass::addSpecialType(specialType s)
{
    sType.push_back(s);
    return this;
}
void umlClass::removeSpecialType(specialType s)
{
    sType.remove(s);
}
umlClass* umlClass::addAttribute(umlAttribute* a)
{
    attributes.push_back(a);
    return this;
}
umlClass* umlClass::addFunction(umlFunction* f)
{
    functions.push_back(f);
    return this;
}
umlClass* umlClass::removeAttribute(umlAttribute* a)
{
    attributes.remove(a);
    return this;
}
umlClass* umlClass::removeFunction(umlFunction* f)
{
    functions.remove(f);
    return this;
}
const string &umlClass::getName()
{
    return name;
}
accessability umlClass::getAccessability()
{
    return accessability_;
}
list<specialType>& umlClass::getSpecialType()
{
    return sType;
}
list<umlAttribute*>& umlClass::getAttributes()
{
    return attributes;
}

list<umlFunction*>& umlClass::getFunctions()
{
	return functions;
}
string umlClass::getString()
{
    string tmp = getStringT(accessability_);
    for (list<specialType>::iterator it = sType.begin();
            it != sType.end(); ++it)
    {
        tmp += getStringT(*it);
    }

    tmp += name;
    tmp += "\n\nAttributes\n";

    for (list<umlAttribute*>::iterator it = attributes.begin();
            it != attributes.end(); ++it)
    {
        tmp += "\t" + (*it)->getString() + "\n";
    }

    tmp += "\nFunctions\n";
    for (list<umlFunction*>::iterator it = functions.begin();
            it != functions.end(); ++it)
    {
        tmp += "\t" + (*it)->getString() + "\n";
    }
    return tmp;
}

#include "umlAttribute.h"


umlAttribute::umlAttribute()
{
    name = "foo";
    accessability_ = none_;
}
umlAttribute* umlAttribute::setName(string n)
{
    name = n;
    return this;
}
umlAttribute* umlAttribute::setAccessability(accessability a)
{
    accessability_ = a;
    return this;
}
umlAttribute* umlAttribute::setType(umlType* t)
{
    type = t;
    return this;
}
umlAttribute* umlAttribute::addSpecialType(specialType s)
{
    sType.push_back(s);
    return this;
}
void umlAttribute::removeSpecialType(specialType s)
{
    sType.remove(s);
}

string umlAttribute::getName()
{
    return name;
}
accessability umlAttribute::getAccessability()
{
    return accessability_;
}
umlType* umlAttribute::getType()
{
    return type;
}
list<specialType> umlAttribute::getSpecialType()
{
    return sType;
}

string umlAttribute::getString()
{
    string tmp;
    for (list<specialType>::iterator it = sType.begin();
            it != sType.end(); ++it)
    {
        tmp += getStringT(*it);
    }
    return getStringT(accessability_) + tmp + type->getString() + " "
                    + name;
}

#ifndef UMLFUNCTION_H
#define UMLFUNCTION_H

#include "umlAttribute.h"

class umlFunction
{
    private:
        string name;
        accessability accessability_;
        umlType* type;
        list<specialType> sType;
        list<umlAttribute*> params;
    public:
        umlFunction();
        umlFunction* setName(string n);
        umlFunction* setAccessability(accessability a);
        umlFunction* setType(umlType* t);
        umlFunction* addSpecialType(specialType s);
        umlFunction* removeSpecialType(specialType s);
        umlFunction* addParam(umlAttribute* p);
        umlFunction* removeParam(umlAttribute* p);
        string getName();
        accessability getAccessability();
        umlType* getType();
        list<specialType> getSpecialType();
        list<umlAttribute*> getParams();
        string getString();
};

#endif

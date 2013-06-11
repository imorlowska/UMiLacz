#ifndef UMLCLASS_H
#define UMLCLASS_H

#include "umlFunction.h"

class umlClass
{
    private:
        string name;
        accessability accessability_;
        list<specialType> sType;

        list<umlFunction*> functions;
        list<umlAttribute*> attributes;
    public:
        umlClass();
		umlClass* setName(const string& n);
        umlClass* setAccessability(accessability a);
        umlClass* addSpecialType(specialType s);
        void removeSpecialType(specialType s);
        umlClass* addAttribute(umlAttribute* a);
        umlClass* addFunction(umlFunction* f);
        umlClass* removeAttribute(umlAttribute* a);
        umlClass* removeFunction(umlFunction* f);
		const string& getName();
        accessability getAccessability();
        list<specialType>& getSpecialType();
        list<umlAttribute*>& getAttributes();
		list<umlFunction*>& getFunctions();
        string getString();
};

#endif

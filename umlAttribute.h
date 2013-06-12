#ifndef UMLATTRIBUTE_H
#define UMLATTRIBUTE_H

#include "umlType.h"

class umlAttribute
{
    private:
        string name;
        accessability accessability_;
        umlType* type;
        list<specialType> sType;
    public:
        umlAttribute();
        umlAttribute* setName(string n);
        umlAttribute* setAccessability(accessability a);
        umlAttribute* setType(umlType* t);
        umlAttribute* addSpecialType(specialType s);

        void removeSpecialType(specialType s);

        string getName();
        accessability getAccessability();
        umlType* getType();
        list<specialType> getSpecialType();
        string getString();

};

#endif

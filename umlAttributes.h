#ifndef UMLATTRIBUTES_H
#define UMLATTRIBUTES_H

#include "umlType.h"

class umlAttributes
{
    private:
        string name;
        accessability accessability_;
        umlType* type;
        list<specialType> sType;
    public:
        umlAttributes* setName(string n)
        {
            name = n;
            return this;
        }
        umlAttributes* setAccessability(accessability a)
        {
            accessability_ = a;
            return this;
        }
        umlAttributes* setType(umlType* t)
        {
            type = t;
            return this;
        }
        umlAttributes* addSpecialType(specialType s)
        {
            sType.push_back(s);
        }
        void removeSpecialType(specialType s)
        {
            sType.remove(s);
        }

        string getName()
        {
            return name;
        }
        accessability getAccessability()
        {
            return accessability_;
        }
        umlType* getType()
        {
            return type;
        }
        list<specialType> getSpecialType()
        {
            return sType;
        }

};

#endif

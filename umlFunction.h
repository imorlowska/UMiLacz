#ifndef UMLFUNCTION_H
#define UMLFUNCTION_H

#include "umlAttributes.h"

class umlFunction
{
    private:
        string name;
        accessability accessability_;
        umlType* type;
        list<specialType> sType;
        list<umlAttributes*> params;
    public:
        umlFunction* setName(string n)
        {
            name = n;
            return this;
        }
        umlFunction* setAccessability(accessability a)
        {
            accessability_ = a;
            return this;
        }
        umlFunction* setType(umlType* t)
        {
            type = t;
            return this;
        }
        umlFunction* addSpecialType(specialType s)
        {
            sType.push_back(s);
        }
        void removeSpecialType(specialType s)
        {
            sType.remove(s);
        }
        void addParam(umlAttributes* p)
        {
            params.push_back(p);
        }
        void removeParam(umlAttributes* p)
        {
            params.remove(p);
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
        list<umlAttributes*> getParams()
        {
            return params;
        }
};

#endif

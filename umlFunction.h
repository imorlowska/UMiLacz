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
            return this;
        }
        umlFunction* removeSpecialType(specialType s)
        {
            sType.remove(s);
            return this;
        }
        umlFunction* addParam(umlAttributes* p)
        {
            params.push_back(p);
            return this;
        }
        umlFunction* removeParam(umlAttributes* p)
        {
            params.remove(p);
            return this;
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
        string getString()
        {
            string spec;
            for (list<specialType>::iterator it = sType.begin();
                    it != sType.end(); ++it)
            {
                spec += getStringT(*it);
            }
            string param;
            for (list<umlAttributes*>::iterator it = params.begin();
                    it != params.end(); ++it)
            {
                param += (*it)->getString() + ", ";
            }
            if(param.length()>2)
            {
                param.erase(param.length()-2, param.length());
            }
            param = "(" + param + ")";

            return getStringT(accessability_) + spec + type->getString() + " "
                            + name + param;
        }
};

#endif

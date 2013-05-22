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
        list<umlAttributes*> attributes;
    public:
        umlClass* setName(string n)
        {
            name = n;
            return this;
        }
        umlClass* setAccessability(accessability a)
        {
            accessability_ = a;
            return this;
        }
        umlClass* addSpecialType(specialType s)
        {
            sType.push_back(s);
            return this;
        }
        void removeSpecialType(specialType s)
        {
            sType.remove(s);
        }
        umlClass* addAttribute(umlAttributes* a)
        {
            attributes.push_back(a);
            return this;
        }
        umlClass* addFunction(umlFunction* f)
        {
            functions.push_back(f);
            return this;
        }
        umlClass* removeAttribute(umlAttributes* a)
        {
            attributes.remove(a);
            return this;
        }
        umlClass* removeFunction(umlFunction* f)
        {
            functions.remove(f);
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
        list<specialType> getSpecialType()
        {
            return sType;
        }
        list<umlAttributes*> getAttributes()
        {
            return attributes;
        }
        string getString()
        {
            string tmp = getStringT(accessability_);
            for (list<specialType>::iterator it = sType.begin();
                    it != sType.end(); ++it)
            {
                tmp += getStringT(*it);
            }

            tmp += name;
            tmp += "\n\nAttributes\n";

            for (list<umlAttributes*>::iterator it = attributes.begin();
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
};

#endif

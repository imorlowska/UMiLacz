#ifndef UMLDIAGRAM_H
#define UMLDIAGRAM_H

#include "umlClass.h"

class umlDiagram
{
    private:
        list <umlClass*> classes;
        map < pair <umlClass*, umlClass*>,
              pair<connectionType, connectionNumber> > dependencies;
        string name;
    public:
        umlDiagram(string name)
        {
            this->name = name;
        }
        void addClass(umlClass* c)
        {
            classes.push_back(c);
        }
        void removeClass(umlClass* c)
        {
            classes.remove(c);
        }
        void rename(string name)
        {
            this->name = name;
        }
        void addDependencies(umlClass* c1, umlClass* c2, connectionType ct,
                             connectionNumber cn)
        {
            dependencies.insert(pair <pair <umlClass*, umlClass*>,
                                      pair<connectionType, connectionNumber> >
                                (pair<umlClass*,umlClass*>(c1,c2),
                                 pair<connectionType,connectionNumber>(ct,cn)));
        }
        string getName()
        {
            return name;
        }
        list<umlClass*> getClasses()
        {
            return classes;
        }
        map<pair<umlClass*, umlClass*>,pair<connectionType, connectionNumber> >
            getDependencies()
        {
            return dependencies;
        }

};

#endif

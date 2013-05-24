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
        umlDiagram();
        umlDiagram* addClass(umlClass* c);
        void removeClass(umlClass* c);
        umlDiagram* setName(string name);
        umlDiagram* addDependency(umlClass* c1, umlClass* c2, connectionType ct,
                             connectionNumber cn);
        string getName();
        list<umlClass*> getClasses();
        map<pair<umlClass*, umlClass*>,pair<connectionType, connectionNumber> >
            getDependencies();
        string getString();
};

#endif

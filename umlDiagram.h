#ifndef UMLDIAGRAM_H
#define UMLDIAGRAM_H

#include "umlClass.h"
#include "tuple"

class umlDiagram
{
    private:
        list <umlClass*> classes;
		list <tuple<umlClass*,umlClass*,
				connectionType,connectionNumber>> dependencies;
        string name;
    public:
        umlDiagram();
        umlDiagram* addClass(umlClass* c);
        void removeClass(umlClass* c);
        umlDiagram* setName(string name);
        umlDiagram* addDependency(umlClass* c1, umlClass* c2, connectionType ct,
                             connectionNumber cn);
        string getName();
		list<umlClass *> &getClasses();
		list <tuple<umlClass*,umlClass*,connectionType,connectionNumber>>& getDependencies();
        string getString();
};

#endif

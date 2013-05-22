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
        umlDiagram* addClass(umlClass* c)
        {
            classes.push_back(c);
            return this;
        }
        void removeClass(umlClass* c)
        {
            classes.remove(c);
        }
        umlDiagram* setName(string name)
        {
            this->name = name;
            return this;
        }
        umlDiagram* addDependency(umlClass* c1, umlClass* c2, connectionType ct,
                             connectionNumber cn)
        {
            dependencies.insert(pair <pair <umlClass*, umlClass*>,
                                      pair<connectionType, connectionNumber> >
                                (pair<umlClass*,umlClass*>(c1,c2),
                                 pair<connectionType,connectionNumber>(ct,cn)));
            return this;
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

        string getString()
        {
            string tmp = "Diagram: " + name + "\n\nClasses\n";

            for (list<umlClass*>::iterator it = classes.begin();
                    it != classes.end(); ++it)
            {
                tmp += "\t" + (*it)->getString() + "\n";
            }
            return tmp;
        }
};

#endif

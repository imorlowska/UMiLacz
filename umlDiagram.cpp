#include "umlDiagram.h"

umlDiagram::umlDiagram()
{
    name = "Sample Diagram";
}
umlDiagram* umlDiagram::addClass(umlClass* c)
{
    classes.push_back(c);
    return this;
}
void umlDiagram::removeClass(umlClass* c)
{
    classes.remove(c);
}
umlDiagram* umlDiagram::setName(string name)
{
    this->name = name;
    return this;
}
umlDiagram* umlDiagram::addDependency(umlClass* c1, umlClass* c2, connectionType ct,
                     connectionNumber cn)
{
    dependencies.insert(pair <pair <umlClass*, umlClass*>,
                              pair<connectionType, connectionNumber> >
                        (pair<umlClass*,umlClass*>(c1,c2),
                         pair<connectionType,connectionNumber>(ct,cn)));
    return this;
}
string umlDiagram::getName()
{
    return name;
}
list<umlClass*> umlDiagram::getClasses()
{
    return classes;
}
map<pair<umlClass*, umlClass*>,pair<connectionType, connectionNumber> >
    umlDiagram::getDependencies()
{
    return dependencies;
}

string umlDiagram::getString()
{
    string tmp = "Diagram: " + name + "\n\nClasses\n";

    for (list<umlClass*>::iterator it = classes.begin();
            it != classes.end(); ++it)
    {
        tmp += "\t" + (*it)->getString() + "\n";
    }
    return tmp;
}

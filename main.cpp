#include <iostream>

#include "umlDiagram.h"


int main()
{
    umlSimpleType* t = new umlSimpleType();
    t->setType(int_);
    umlAttributes* a = new umlAttributes;
    a->setAccessability(private_)->setName("foo")->setType(t);

    cout << getString(a->getAccessability()) << " " << a->getName() << endl;

    return 0;
}

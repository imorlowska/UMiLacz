#include <iostream>

#include "umlDiagram.h"


int main()
{
    umlBinaryType* t = new umlBinaryType();
    umlSimpleType* t1 = new umlSimpleType();
    umlInternalType* t2 = new umlInternalType();
    t1->setType(int_);
    t2->setType("myType*");
    t->setType(pair_, t1, t2);

    umlFunction* f = new umlFunction();
    f->setAccessability(private_)->setName("foo")->setType(t)->
                addSpecialType(static_)->addSpecialType(interface_);

    umlAttributes* p1 = new umlAttributes();
    p1->setType(t1)->setName("param1");

    umlAttributes* p2 = new umlAttributes();
    p2->setType(t2)->setName("param2");

    f->addParam(p1)->addParam(p2);
    cout << f->getString() << endl;

    return 0;
}

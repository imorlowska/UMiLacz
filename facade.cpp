#include "facade.h"

Facade::Facade()
{
    diagram = new umlDiagram();
}

void Facade::sample()
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

    umlAttribute* p1 = new umlAttribute();
    p1->setType(t1)->setName("param1");

    umlAttribute* p2 = new umlAttribute();
    p2->setType(t2)->setName("param2");

    f->addParam(p1)->addParam(p2);
    //cout << f->getString() << endl;

    umlClass* c = new umlClass();
    c->setName("MyClass")->setAccessability(public_)->addFunction(f)->
            addSpecialType(abstract_)->addAttribute(p1)->addAttribute(p2);

    //cout << c->getString() << endl;

    umlDiagram* d = new umlDiagram();

    d->addClass(c)->addClass(c->removeAttribute(p2)->setName("Klasa2"))
                                ->setName("Przykladowy");

    cout << d->getString() << endl;
}

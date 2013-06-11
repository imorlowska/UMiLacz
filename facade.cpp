#include "facade.h"
#include "converter2cpp.h"

Facade::Facade()
{
    diagram = new umlDiagram();
}

void Facade::sample()
{
    umlBinaryType* t = new umlBinaryType();
    umlSimpleType* t1 = new umlSimpleType();
    umlInternalType* t2 = new umlInternalType();
    umlSimpleType* t3 = new umlSimpleType();
    t1->setType(int_);
    t2->setType("myType*");
    t3->setType(string_);

    t->setType(pair_, t1, t2);

    umlFunction* f = new umlFunction();
    f->setAccessability(private_)->setName("foo")->setType(t)->
                addSpecialType(static_);

    umlAttribute* p1 = new umlAttribute();
    p1->setType(t1)->setName("param1");

    umlAttribute* p2 = new umlAttribute();
    p2->setType(t2)->setName("param2");

    f->addParam(p1)->addParam(p2);

    umlFunction* f2 = new umlFunction();
    f2->setAccessability(public_)->setName("foo2")->setType(t3);

    umlAttribute* p3 = new umlAttribute();
    p3->setType(t3)->setAccessability(protected_)->setName("name");

    umlAttribute* p4 = new umlAttribute();
    p4->setType(t2)->setAccessability(private_)->setName("attributeNb");

    umlClass* c = new umlClass();
    c->setName("MyClass")->setAccessability(public_)->addFunction(f)->
            addFunction(f2)->addAttribute(p3)->addAttribute(p4);


    //cout << c->getString() << endl;

    umlDiagram* d = new umlDiagram();

    d->addClass(c)->setName("Przykladowy");

    //cout << d->getString() << endl;

    converter2cpp* cpp = new converter2cpp();
    cpp->convert(d);
}

#include "facade.h"
#include "converter2cpp.h"
#include "converter2java.h"

Facade::Facade()
{
    diagram = new umlDiagram();
}

umlDiagram* Facade::sampleDiagram()
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
    string name = "MyClass";
    c->setName(name)->setAccessability(public_)->addFunction(f)->
            addFunction(f2)->addAttribute(p3)->addAttribute(p4);

    umlClass* c2 = new umlClass();
    string name2 = "MyClass2";
    c2->setName(name2)->setAccessability(private_)->addFunction(f)->
            addFunction(f2)->addAttribute(p3)->addAttribute(p4);

    umlDiagram* d = new umlDiagram();

    d->addClass(c)->addClass(c2)->addDependency(c,c2,extends_,one2one)->
            setName("Przykladowy");

    return d;
}

void Facade::generateCpp(umlDiagram* diagram)
{
    converter2cpp* cpp = new converter2cpp();
    cpp->convert(diagram);
}

void Facade::generateJava(umlDiagram* diagram)
{
    converter2java* java = new converter2java();
    java->convert(diagram);
}

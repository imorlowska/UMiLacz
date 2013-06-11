#ifndef UMLTYPE_H
#define UMLTYPE_H

#include "typedefs.h"

class umlType
{
    public:
        typeKinds typeKind;
        virtual string getString() = 0;
};

class umlInternalType:public umlType
{
    private:
        string name;
    public:
        umlInternalType();
        umlInternalType* setType(string s);
        string getString();
};

class umlSimpleType:public umlType
{
    private:
        simpleType name;
    public:
        umlSimpleType();
        umlSimpleType* setType(simpleType t);
        simpleType getType();
        string getString();
};

class umlUnaryType:public umlType
{
    private:
        complexTypeUnary name;
        umlType* inside;
    public:
        umlUnaryType();
        umlUnaryType* setType(complexTypeUnary t, umlType* i);
        pair<complexTypeUnary, umlType*> getType();
        string getString();
};


class umlBinaryType:public umlType
{
    private:
        complexTypeBinary name;
        umlType* insideFirst;
        umlType* insideSecond;
    public:
        umlBinaryType();
        umlBinaryType* setType(complexTypeBinary t, umlType* i1, umlType* i2);
        pair<complexTypeBinary,pair<umlType*,umlType*> > getType();
        string getString();
};

#endif

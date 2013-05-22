#ifndef UMLTYPE_H
#define UMLTYPE_H

#include "typedefs.h"

class umlType
{
    protected:
        typeKinds typeKind;
    public:
        virtual string getString() = 0;
};

class umlInternalType:public umlType
{
    private:
        string name;
    public:
        umlInternalType()
        {
            typeKind = internal_;
        }
        umlInternalType* setType(string s)
        {
            name = s;
            return this;
        }
        string getString()
        {
            return name;
        }
};

class umlSimpleType:public umlType
{
    private:
        simpleType name;
    public:
        umlSimpleType()
        {
            typeKind = simple_;
        }
        umlSimpleType* setType(simpleType t)
        {
            name = t;
            return this;
        }
        simpleType getType()
        {
            return name;
        }
        string getString()
        {
            return getStringT(name);
        }
};

class umlUnaryType:public umlType
{
    private:
        complexTypeUnary name;
        umlType* inside;
    public:
        umlUnaryType()
        {
            typeKind = unary_;
        }
        umlUnaryType* setType(complexTypeUnary t, umlType* i)
        {
            name = t;
            inside = i;
            return this;
        }
        pair<complexTypeUnary, umlType*> getType()
        {
            return pair<complexTypeUnary,umlType*>(name, inside);
        }
        string getString()
        {
            return getStringT(name) + "< " + inside->getString() + " >";
        }
};

class umlBinaryType:public umlType
{
    private:
        complexTypeBinary name;
        umlType* insideFirst;
        umlType* insideSecond;
    public:
        umlBinaryType()
        {
            typeKind = binary_;
        }
        umlBinaryType* setType(complexTypeBinary t, umlType* i1, umlType* i2)
        {
            name = t;
            insideFirst = i1;
            insideSecond = i2;
            return this;
        }
        pair<complexTypeBinary,pair<umlType*,umlType*> > getType()
        {
            return pair<complexTypeBinary, pair<umlType*,umlType*> >
                    (name, pair<umlType*,umlType*> (insideFirst, insideSecond));
        }
        string getString()
        {
            return getStringT(name) + "< " + insideFirst->getString()
                                    + ", " + insideSecond->getString() + " >";
        }
};

#endif

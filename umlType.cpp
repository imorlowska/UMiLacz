#include "umlType.h"

umlInternalType::umlInternalType()
{
    typeKind = internal_;
}
umlInternalType* umlInternalType::setType(string s)
{
    name = s;
    return this;
}
string umlInternalType::getString()
{
    return name;
}


umlSimpleType::umlSimpleType()
{
    typeKind = simple_;
}
umlSimpleType* umlSimpleType::setType(simpleType t)
{
    name = t;
    return this;
}
simpleType umlSimpleType::getType()
{
    return name;
}
string umlSimpleType::getString()
{
    return getStringT(name);
}


umlUnaryType::umlUnaryType()
{
    typeKind = unary_;
}
umlUnaryType* umlUnaryType::setType(complexTypeUnary t, umlType* i)
{
    name = t;
    inside = i;
    return this;
}
pair<complexTypeUnary, umlType*> umlUnaryType::getType()
{
    return pair<complexTypeUnary,umlType*>(name, inside);
}
string umlUnaryType::getString()
{
    return getStringT(name) + "< " + inside->getString() + " >";
}


umlBinaryType::umlBinaryType()
{
    typeKind = binary_;
}
umlBinaryType* umlBinaryType::setType(complexTypeBinary t, umlType* i1, umlType* i2)
{
    name = t;
    insideFirst = i1;
    insideSecond = i2;
    return this;
}
pair<complexTypeBinary,pair<umlType*,umlType*> > umlBinaryType::getType()
{
    return pair<complexTypeBinary, pair<umlType*,umlType*> >
            (name, pair<umlType*,umlType*> (insideFirst, insideSecond));
}
string umlBinaryType::getString()
{
    return getStringT(name) + "< " + insideFirst->getString()
                            + ", " + insideSecond->getString() + " >";
}

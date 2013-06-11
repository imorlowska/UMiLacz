#include "converter2cpp.h"

inline std::string trim(std::string& str)
{
str.erase(0, str.find_first_not_of(' '));
str.erase(str.find_last_not_of(' ')+1);
return str;
}

void converter2cpp::convert(umlDiagram* currentDiagram)
{
    this->diagram = currentDiagram;

    for(umlClass* current:diagram->getClasses())
    {
        generateHeaderFile(current);
    }
}

void converter2cpp::generateHeaderFile(umlClass* currentClass)
{
    ofstream headerFile;
    headerFile.open("output\\" + currentClass->getName() + ".h");

    headerFile << "\n";
    headerFile << getStringT(currentClass->getAccessability());
    for(specialType type:currentClass->getSpecialType())
    {
        headerFile << getStringT(type);
    }
    headerFile << currentClass->getName() + "\n{\n";

    headerFile << "\tprivate:\n";
    fillPrivateAttributes(headerFile, currentClass);
    fillPrivateFunctions(headerFile, currentClass);

    headerFile << "\tprotected:\n";
    fillProtectedAttributes(headerFile, currentClass);
    fillProtectedFunctions(headerFile, currentClass);

    headerFile << "\tpublic:\n";
    fillPublicAttributes(headerFile, currentClass);
    fillPublicFunctions(headerFile, currentClass);

    headerFile << "};\n";
    headerFile.close();
}

void converter2cpp::fillPrivateAttributes(ofstream& file, umlClass* currentClass)
{
    for(umlAttribute* att:currentClass->getAttributes())
    {
        if (att->getAccessability() == private_)
        {
            string tmp = att->getString();
            tmp.erase(0, 7);
            file << "\t\t" + trim(tmp) << endl;
        }
    }
}
void converter2cpp::fillPrivateFunctions(ofstream& file, umlClass* currentClass)
{
    for(umlFunction* func:currentClass->getFunctions())
    {
        if (func->getAccessability() == private_)
        {
            string tmp = func->getString();
            tmp.erase(0, 7);
            file << "\t\t" + trim(tmp) << endl;
        }
    }
}
void converter2cpp::fillProtectedAttributes(ofstream& file, umlClass* currentClass)
{
    for(umlAttribute* att:currentClass->getAttributes())
    {
        if (att->getAccessability() == protected_)
        {
            string tmp = att->getString();
            tmp.erase(0, 9);
            file << "\t\t" + trim(tmp) << endl;
        }
    }
}
void converter2cpp::fillProtectedFunctions(ofstream& file, umlClass* currentClass)
{
    for(umlFunction* func:currentClass->getFunctions())
    {
        if (func->getAccessability() == protected_)
        {
            string tmp = func->getString();
            tmp.erase(0, 9);
            file << "\t\t" + trim(tmp) << endl;
        }
    }
}
void converter2cpp::fillPublicAttributes(ofstream& file, umlClass* currentClass)
{
    for(umlAttribute* att:currentClass->getAttributes())
    {
        if (att->getAccessability() == public_)
        {
            string tmp = att->getString();
            tmp.erase(0, 6);
            file << "\t\t" + trim(tmp) << endl;
        }
    }
}
void converter2cpp::fillPublicFunctions(ofstream& file, umlClass* currentClass)
{
    for(umlFunction* func:currentClass->getFunctions())
    {
        if (func->getAccessability() == public_)
        {
            string tmp = func->getString();
            tmp.erase(0, 6);
            file << "\t\t" + trim(tmp) << endl;
        }
    }
}

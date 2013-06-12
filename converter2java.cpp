#include "converter2java.h"

string trim(std::string& str);

void converter2java::convert(umlDiagram* currentDiagram)
{
    this->diagram = currentDiagram;

    for(umlClass* current:diagram->getClasses())
    {
        generateHeaderFile(current);
    }
}

void converter2java::generateHeaderFile(umlClass* currentClass)
{
    ofstream headerFile;
    headerFile.open("output\\" + currentClass->getName() + ".java");

    fillAutomatedMessage(headerFile);

    headerFile << "\n";
    headerFile << getStringT(currentClass->getAccessability());
    for(specialType type:currentClass->getSpecialType())
    {
        headerFile << getStringT(type);
    }
    headerFile << currentClass->getName() + " {\n";

    headerFile << "\t//attributes\n";
    fillPrivateAttributes(headerFile, currentClass);
    fillProtectedAttributes(headerFile, currentClass);
    fillPublicAttributes(headerFile, currentClass);

    headerFile << "\n\t//methods\n";
    fillPrivateFunctions(headerFile, currentClass);
    fillProtectedFunctions(headerFile, currentClass);
    fillPublicFunctions(headerFile, currentClass);

    headerFile << "};\n";
    headerFile.close();
}

void converter2java::fillAutomatedMessage(ofstream& file)
{
    file << "//\n";
    file << "//Java file generated by UMiLacz v 1.0\n";
    file << "//\n";
    file << "//@Autors: Alexander Myronov & Izabela Orlowska\n";
    file << "//\n";
}

void converter2java::fillPrivateAttributes(ofstream& file, umlClass* currentClass)
{
    for(umlAttribute* att:currentClass->getAttributes())
    {
        if (att->getAccessability() == private_)
        {
            string tmp = att->getString();
            file << "\t" + trim(tmp) + ";" << endl;
        }
    }
}
void converter2java::fillPrivateFunctions(ofstream& file, umlClass* currentClass)
{
    for(umlFunction* func:currentClass->getFunctions())
    {
        if (func->getAccessability() == private_)
        {
            string tmp = func->getString();
            file << "\t" + trim(tmp) + ";" << endl;
        }
    }
}
void converter2java::fillProtectedAttributes(ofstream& file, umlClass* currentClass)
{
    for(umlAttribute* att:currentClass->getAttributes())
    {
        if (att->getAccessability() == protected_)
        {
            string tmp = att->getString();
            file << "\t" + trim(tmp) + ";" << endl;
        }
    }
}
void converter2java::fillProtectedFunctions(ofstream& file, umlClass* currentClass)
{
    for(umlFunction* func:currentClass->getFunctions())
    {
        if (func->getAccessability() == protected_)
        {
            string tmp = func->getString();
            file << "\t" + trim(tmp) + ";" << endl;
        }
    }
}
void converter2java::fillPublicAttributes(ofstream& file, umlClass* currentClass)
{
    for(umlAttribute* att:currentClass->getAttributes())
    {
        if (att->getAccessability() == public_)
        {
            string tmp = att->getString();;
            file << "\t" + trim(tmp) + ";" << endl;
        }
    }
}
void converter2java::fillPublicFunctions(ofstream& file, umlClass* currentClass)
{
    for(umlFunction* func:currentClass->getFunctions())
    {
        if (func->getAccessability() == public_)
        {
            string tmp = func->getString();
            file << "\t" + trim(tmp) + ";" << endl;
        }
    }
}

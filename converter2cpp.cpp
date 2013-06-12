#include "converter2cpp.h"

string trim(std::string& str)
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

    fillAutomatedMessage(headerFile);

    fillDepencencyInclude(headerFile, currentClass);

    headerFile << "\n";
    headerFile << "class " << currentClass->getName();

    fillDependencyMessage(headerFile, currentClass);

    headerFile << "\n{\n";

    headerFile << "\t//default:\n";
    fillDefaultAttributes(headerFile, currentClass);
    fillDefaultFunctions(headerFile, currentClass);

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

void converter2cpp::fillAutomatedMessage(ofstream& file)
{
    file << "//\n";
    file << "//C++ header file generated by UMiLacz v 1.0\n";
    file << "//\n";
    file << "//@Autors: Alexander Myronov & Izabela Orlowska\n";
    file << "//\n";
}

void converter2cpp::fillDepencencyInclude(ofstream& file, umlClass* currentClass)
{
    list<string> toInclude;
    for(tuple<umlClass *, umlClass *, connectionType, connectionNumber>
                    line:diagram->getDependencies())
    {
        if (get<0>(line) == currentClass && get<2>(line) == extends_)
        {
            toInclude.push_back(get<1>(line)->getName());
        }
    }
    if (toInclude.size() > 0)
    {
        for(string name:toInclude)
        {
            file << "#include <" + name + ".h>\n";
        }
    }
}

void converter2cpp::fillDependencyMessage(ofstream& file, umlClass* currentClass)
{
    list<string> toInclude;
    for(tuple<umlClass *, umlClass *, connectionType, connectionNumber>
                    line:diagram->getDependencies())
    {
        if (get<0>(line) == currentClass && get<2>(line) == extends_)
        {
            toInclude.push_back(get<1>(line)->getName());
        }
    }
    if (toInclude.size() > 0)
    {
        file << ":";
        for(string name:toInclude)
        {
            file << " public " + name;
        }
    }
}

void converter2cpp::fillDefaultAttributes(ofstream& file, umlClass* currentClass)
{
    for(umlAttribute* att:currentClass->getAttributes())
    {
        if (att->getAccessability() == none_)
        {
            string tmp = att->getString();
            file << "\t\t" + trim(tmp) + ";" << endl;
        }
    }
}
void converter2cpp::fillDefaultFunctions(ofstream& file, umlClass* currentClass)
{
    for(umlFunction* func:currentClass->getFunctions())
    {
        if (func->getAccessability() == none_)
        {
            string tmp = func->getString();
            file << "\t\t" + trim(tmp) + ";" << endl;
        }
    }
}
void converter2cpp::fillPrivateAttributes(ofstream& file, umlClass* currentClass)
{
    for(umlAttribute* att:currentClass->getAttributes())
    {
        if (att->getAccessability() == private_)
        {
            string tmp = att->getString();
            tmp.erase(0, 7);
            file << "\t\t" + trim(tmp) + ";" << endl;
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
            file << "\t\t" + trim(tmp) + ";" << endl;
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
            file << "\t\t" + trim(tmp) + ";" << endl;
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
            file << "\t\t" + trim(tmp) + ";" << endl;
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
            file << "\t\t" + trim(tmp) + ";" << endl;
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
            file << "\t\t" + trim(tmp) + ";" << endl;
        }
    }
}

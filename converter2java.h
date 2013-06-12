#ifndef CONVERTER2JAVA_H
#define CONVERTER2JAVA_H

#include "converter.h"


class converter2java: private converter
{
    private:
        void generateHeaderFile(umlClass* currentClass);

        void fillAutomatedMessage(ofstream& file);
        void fillPrivateAttributes(ofstream& file, umlClass* currentClass);
        void fillPrivateFunctions(ofstream& file, umlClass* currentClass);
        void fillProtectedAttributes(ofstream& file, umlClass* currentClass);
        void fillProtectedFunctions(ofstream& file, umlClass* currentClass);
        void fillPublicAttributes(ofstream& file, umlClass* currentClass);
        void fillPublicFunctions(ofstream& file, umlClass* currentClass);
    public:
        void convert(umlDiagram* diagram);
};

#endif

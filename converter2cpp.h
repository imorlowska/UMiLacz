#ifndef CONVERTER2CPP_H
#define CONVERTER2CPP_H

#include "converter.h"


class converter2cpp: private converter
{
    private:
        void generateHeaderFile(umlClass* currentClass);

        void fillDepencencyInclude(ofstream& file, umlClass* currentClass);
        void fillDependencyMessage(ofstream& file, umlClass* currentClass);
        void fillAutomatedMessage(ofstream& file);
        void fillDefaultAttributes(ofstream& file, umlClass* currentClass);
        void fillDefaultFunctions(ofstream& file, umlClass* currentClass);
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

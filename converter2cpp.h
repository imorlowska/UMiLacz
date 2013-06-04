#ifndef CONVERTER2CPP_H
#define CONVERTER2CPP_H

#include "converter.h"


class converter2cpp: private converter
{
    private:
        list<fstream> files;
        fstream* generateHeaderFile(umlClass* currentClass);
        fstream* generateLibrariesHeader();
};

#endif

#ifndef FACADE_H
#define FACADE_H

#include "converter2cpp.h"


class Facade
{
    private:
        umlDiagram* diagram;
    public:
        Facade();
        static umlDiagram* sampleDiagram();
        static void generateCpp(umlDiagram*);
        static void generateJava(umlDiagram*);
};

#endif

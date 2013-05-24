#ifndef FACADE_H
#define FACADE_H

#include "umlDiagram.h"


class Facade
{
    private:
        umlDiagram* diagram;
    public:
        Facade();
        static void sample();
};

#endif

#ifndef CONVERTER_H
#define CONVERTER_H

#include "umlDiagram.h"


class converter
{
    protected:
        umlDiagram* diagram;
        void fillAutomatedMessage(ofstream&);
    public:
        virtual void convert(umlDiagram* diagram) = 0;
};

#endif

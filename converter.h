#ifndef CONVERTER_H
#define CONVERTER_H

#include "umlDiagram.h"


class converter
{
    protected:
        umlDiagram* diagram;
        static converter* instance;

        converter();
    public:
        static converter* getInstance();
        virtual void convert(umlDiagram* diagram) const = 0;
};

#endif

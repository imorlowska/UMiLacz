#include "facade.h"

int main()
{
    Facade::generateCpp(Facade::sampleDiagram());
    Facade::generateJava(Facade::sampleDiagram());
    return 0;
}

#include "converter.h"

converter* converter::getInstance()
{
    if (instance == NULL)
    {
        instance = new converter();
    }
    return instance;
}

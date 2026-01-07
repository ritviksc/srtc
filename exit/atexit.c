#include "atexit.h"

void atexit(void *(function)(void))
{
    atexit_function[atexit_counter++] = function;
}

int __execute_atexit()
{
    if (atexit_counter >= ATEXIT_FUNCTIONS)
    {
        return -1;
    }

    while(atexit_counter >= 0)
    {
        atexit_function[atexit_counter--]();
    }
    
    return 0;

}
#ifndef EXIT_H
#define EXIT_H

#include <stdint.h>

__attribute__((noreturn)) void _exit(uintptr_t status);
__attribute__((noreturn)) void exit(int status);



#endif // EXIT_H
#ifndef CRT_H
#define CRT_H

#include "syscall.h"

/* Process startup _start() */
extern void _start(void);

/* Process termination*/
__attribute__((noreturn)) void _exit(syscall_arg_t status);
__attribute__((noreturn)) void exit(int status);

/**/


#endif // CRT_H
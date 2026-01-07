#include "atexit.h"
#include "syscalls/syscall.h"
#include <stdint.h>

__attribute__((noreturn)) void _exit(uintptr_t status)
{
    __syscall1(SYS_exit,status);
    __builtin_unreachable();

}

__attribute__((noreturn)) void exit(int status)
{
    // Flush buffers, run atexit() functions -> Cleanup
    __execute_atexit();
    _exit(status);
    __builtin_unreachable();    
}
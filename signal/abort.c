#include "exit.h"
#include "syscalls/syscall.h"
#include <signal.h>

__attribute__((noreturn)) void abort()
{
    __syscall2(SYS_exit,syscall_0(SYS_getpid), SIGABRT);
    _exit(128 + SIGABRT);
    __builtin_unreachable();
}

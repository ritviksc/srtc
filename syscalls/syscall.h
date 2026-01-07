#ifndef SYSCALL_H
#define SYSCALL_H

#include <stdint.h>

#define SYS_read 0
#define SYS_write 1
#define SYS_open 2
#define SYS_close 3
#define SYS_mmap 9
#define SYS_munmap 11
#define SYS_brk 12
#define SYS_pipe 23 
#define SYS_dup 32
#define SYS_dup2 33
#define SYS_getpid 39
#define SYS_exit 60
#define SYS_kill 62


typedef uintptr_t syscall_arg_t;
typedef long syscall_ret_t;

extern syscall_ret_t  __syscall0(syscall_arg_t nr);
extern syscall_ret_t  __syscall1(syscall_arg_t nr, syscall_arg_t arg_1);
extern syscall_ret_t  __syscall2(syscall_arg_t nr, syscall_arg_t arg_1 ,syscall_arg_t arg_2);
extern syscall_ret_t  __syscall3(syscall_arg_t nr, syscall_arg_t arg_1 ,syscall_arg_t arg_2, syscall_arg_t arg_3);
extern syscall_ret_t  __syscall4(syscall_arg_t nr, syscall_arg_t arg_1 ,syscall_arg_t arg_2,syscall_arg_t arg_3, syscall_arg_t arg_4);
extern syscall_ret_t  __syscall5(syscall_arg_t nr, syscall_arg_t arg_1 ,syscall_arg_t arg_2,syscall_arg_t arg_3, syscall_arg_t arg_4, syscall_arg_t arg_5);
syscall_ret_t __syscall6(syscall_arg_t nr, syscall_arg_t arg_1 ,syscall_arg_t arg_2,syscall_arg_t arg_3, syscall_arg_t arg_4, syscall_arg_t arg_5, syscall_arg_t arg_6);
    
#endif // SYSCALL_H

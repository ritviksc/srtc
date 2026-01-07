#include <stdint.h>
#include <syscall.h>

// Per the System V ABI manual
/*  1. User-level applications use as integer registers for passing the sequence %rdi, %rsi,
        %rdx, %rcx, %r8 and %r9. The kernel interface uses %rdi, %rsi, %rdx, %r10, %r8 and
        %r9.
    2. A system-call is done via the syscall instruction. The kernel clobbers registers %rcx
        and %r11 but preserves all other registers except %rax.
    3. The number of the syscall has to be passed in register %rax.
    4. System-calls are limited to sixcall_retuments, nocall_retument is passed directly on the
        stack.
    5. Returning from the syscall, register %rax contains the result of the system-call. A
        value in the range between -4095 and -1 indicates an error, it is -errno.
    6. Only values of class INTEGER or class MEMORY are passed to the kernel    */

extern syscall_ret_t  __syscall0(syscall_arg_t nr);
extern syscall_ret_t  __syscall1(syscall_arg_t nr, syscall_arg_t arg_1);
extern syscall_ret_t  __syscall2(syscall_arg_t nr, syscall_arg_t arg_1 ,syscall_arg_t arg_2);
extern syscall_ret_t  __syscall3(syscall_arg_t nr, syscall_arg_t arg_1 ,syscall_arg_t arg_2, syscall_arg_t arg_3);
extern syscall_ret_t  __syscall4(syscall_arg_t nr, syscall_arg_t arg_1 ,syscall_arg_t arg_2,syscall_arg_t arg_3, syscall_arg_t arg_4);
extern syscall_ret_t  __syscall5(syscall_arg_t nr, syscall_arg_t arg_1 ,syscall_arg_t arg_2,syscall_arg_t arg_3, syscall_arg_t arg_4, syscall_arg_t arg_5);

syscall_ret_t __syscall6(syscall_arg_t nr, syscall_arg_t arg_1 ,syscall_arg_t arg_2,syscall_arg_t arg_3, syscall_arg_t arg_4, syscall_arg_t arg_5, syscall_arg_t arg_6)
{
    syscall_ret_t ret;
    register syscall_arg_t r10 __asm__ ("r10") = arg_4;
    register syscall_arg_t r8  __asm__ ("r8")  = arg_5;
    register syscall_arg_t r9  __asm__ ("r9")  = arg_6;
    __asm__ __volatile__
    (
        "syscall"
        : "=a"(ret)
        : "a"(nr), "D"(arg_1), "S"(arg_2), "d"(arg_3), "r"(r10), "r"(r8), "r"(r9)
        : "rcx", "r11", "memory"
    );
    return ret;
}
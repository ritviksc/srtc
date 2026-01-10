.text

.global __syscall0
.type __syscall0, @function
__syscall0:
    mov %rdi, %rax
    syscall
    ret 

.global __syscall1
.type __syscall1, @function
__syscall1:
    mov %rdi, %rax
    mov %rsi,%rdi
    syscall
    ret 

.global __syscall2
.type __syscall2, @function
__syscall2:
    mov %rdi, %rax
    mov %rsi, %rdi
    mov %rdx, %rsi
    syscall
    ret

.global __syscall3
.type __syscall3, @function
__syscall3:
    mov %rdi, %rax
    mov %rsi, %rdi
    mov %rdx, %rsi
    mov %rcx, %rdx
    syscall
    ret

.global __syscall4
.type __syscall4, @function
__syscall4:
    mov %rdi, %rax
    mov %rsi, %rdi
    mov %rdx, %rsi
    mov %rcx, %rdx
    mov %r8, %r10
    syscall
    ret

.global __syscall5
.type __syscall5, @function
__syscall5:
    mov %rdi, %rax
    mov %rsi, %rdi
    mov %rdx, %rsi
    mov %rcx, %rdx
    mov %r8, %r10
    mov %r9, %r8
    syscall
    ret

.section .note.GNU-stack,"",@progbits

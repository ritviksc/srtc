.text

.global _start
.type _start, @function
_start:
    xor %ebp, %ebp
    mov (%rsp), %rdi      # argc
    lea 8(%rsp), %rsi     # argv
    lea 16(%rsp,%rdi,8), %rdx #envp
    and $-16, %rsp    # Align stack address to 16 bytes before we call main
    xor %eax, %eax
    call main
    mov %rax, %rdi
    xor %eax, %eax
    call exit
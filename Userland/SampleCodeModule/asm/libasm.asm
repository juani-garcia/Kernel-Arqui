GLOBAL print, read, try_catch_ud, check_cpuid_support

section .text

print:
    push rbp
    mov rbp, rsp
    
    xor rax, rax
    int 80h

    mov rsp, rbp
    pop rbp
    ret


read:
    push rbp
    mov rbp, rsp

    mov rax, 1
    int 80h

    mov rsp, rbp
    pop rbp
    ret

try_catch_ud:
    push rbp
    mov rbp, rsp

    UD2

    mov rsp, rbp
    pop rbp
    ret

check_cpuid_support:
    push rbp
    mov rbp, rsp

    mov rax, 2
    int 80h

    mov rsp, rbp
    pop rbp
    ret
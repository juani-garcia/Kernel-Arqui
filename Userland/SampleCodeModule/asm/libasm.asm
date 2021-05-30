GLOBAL print, read

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
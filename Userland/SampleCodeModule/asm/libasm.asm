GLOBAL print, scanf

section .text

print:
    push rbp
    mov rsp, rbp
    
    mov rax, 7

    mov rbp, rsp
    pop rbp
    ret

scanf:
    push rbp
    mov rsp, rbp

    mov rax, 1
    int 80h

    mov rax, 0
    int 80h

    mov rbp, rsp
    pop rbp
    ret 
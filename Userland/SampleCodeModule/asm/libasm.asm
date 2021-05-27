GLOBAL print, scanf

print:
    push rbp
    mov rsp, rbp

    xor rax, rax
    int 80h

    mov rbp, rsp
    pop rbp
    ret


scanf:
    push rbp
    mov rsp, rbp

    mov rax, 1
    int 80h

    mov rbp, rsp
    pop rbp
    ret
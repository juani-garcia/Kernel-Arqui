GLOBAL print

print:
    push rbp
    mov rsp, rbp

    xor rax, rax
    int 80h

    mov rbp, rsp
    pop rbp
    ret
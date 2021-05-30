GLOBAL print,  try_catch_ud
print:
    push rbp
    mov rbp, rsp

    xor rax, rax
    int 80h

    mov rsp, rbp
    pop rbp
    ret

try_catch_ud:
    push rbp
    mov rbp, rsp

    UD2

    mov rbp, rsp
    pop rbp
    ret

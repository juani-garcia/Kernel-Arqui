GLOBAL init_process

init_process: ; uint64_t init_process(uint64_t stack_base, uint64_t rip);
    push rbp
    mov rbp, rsp

    mov rsp, rdi

    push 0x00
    push rdi
    push 0x206
    push 0x8
    push rsi
    mov rax, rsp

    mov rsp, rbp
    pop rbp
    ret
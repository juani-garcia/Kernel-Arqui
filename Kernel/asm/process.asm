GLOBAL init_process, get_rsp, run_process

init_process: ; uint64_t init_process(uint64_t stack_base, uint64_t rip);
    push rbp
    push rdi
    push rsi
    mov rbp, rsp 

    mov rsp, rdi
    push 0x00
    push rdi
    push 0x206
    push 0x8
    push rsi
    mov rax, rsp

    mov rsp, rbp
    pop rsi
    pop rdi
    pop rbp
    ret

get_rsp ; uint64_t get_rsp();
    mov rax, rsp
    ret

run_process ; void run_process(uint64_t rsp);
    mov rsp, rdi
    iretq
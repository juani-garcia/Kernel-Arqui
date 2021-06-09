GLOBAL init_process, get_rsp, set_rsp, run_process

init_process: ; uint64_t init_process(uint64_t stack_base, uint64_t rip);
    ; mov rbx, rsp
    ; mov rsp, rdi

    push 0x00
    push rdi
    push 0x206
    push 0x8
    push rsi
    iretq
    mov rax, rsp

    mov rsp, rbx
    ret

get_rsp ; uint64_t get_rsp();
    mov rax, rsp
    ret

set_rsp ; void set_rsp(uint64_t rsp);
    mov rsp, rdi
    ret

run_process ; void run_process(uint64_t rsp);
    mov rsp, rdi
    iretq
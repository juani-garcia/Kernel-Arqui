GLOBAL print, read, try_catch_ud, check_cpuid_support, get_cpuid_info, get_info_reg

section .text

print:
    push rbp
    mov rbp, rsp
    
    mov rax, 1
    int 80h

    mov rsp, rbp
    pop rbp
    ret


read:
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

get_cpuid_info:
    push rbp
    mov rbp, rsp

    mov eax, DWORD [rdi]
    mov ecx, DWORD [rsi]

    cpuid

    mov [rsi], DWORD edx
    mov [rdi], DWORD ecx
    mov [rdx], DWORD ebx

    mov rsp, rbp
    pop rbp
    ret

get_info_reg:
    push rbp
    mov rbp, rsp

    mov rax, 3
    int 80h

    mov rsp, rbp
    pop rbp

    ret

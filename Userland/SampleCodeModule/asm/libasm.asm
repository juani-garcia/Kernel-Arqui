GLOBAL print, read, try_catch_ud, check_cpuid_support, get_cpuid_info, get_info_reg, change_shell, try_catch_zerodiv

section .text

print:
    push rbp
    mov rbp, rsp
    
    mov rax, 0x01
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

try_catch_zerodiv:
    push rbp
    mov rbp, rsp

    mov rdx, 1
    mov rax, 0
    div rax

    mov rsp, rbp
    pop rbp
    ret

check_cpuid_support:
    push rbp
    mov rbp, rsp

    mov rax, 0x02
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

    mov rax, 0x03
    int 80h

    mov rsp, rbp
    pop rbp

    ret

change_shell:
    push rbp
    mov rbp, rsp

    int 81h

    mov rsp, rbp
    pop rbp

    ret

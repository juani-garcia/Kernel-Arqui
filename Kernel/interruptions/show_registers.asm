section .text
GLOBAL show_registers

extern ncPrint
extern ncPrintReg
extern ncNewline

%macro pushRegisters 0
	push rax
	push rbx
	push rcx
	push rdx
	push rbp
	push rdi
	push rsi
	push r8
	push r9
	push r10
	push r11
	push r12
	push r13
	push r14
	push r15
%endmacro

%macro popRegisters 0
	pop r15
	pop r14
	pop r13
	pop r12
	pop r11
	pop r10
	pop r9
	pop r8
	pop rsi
	pop rdi
	pop rbp
	pop rdx
	pop rcx
	pop rbx
	pop rax
%endmacro

show_registers:
    pushRegisters
    mov rdi, reg1
    call ncPrint
    mov rdi, rax
    call ncPrintReg
    call ncNewline
    popRegisters

    pushRegisters
    mov rdi, reg2
    call ncPrint
    mov rdi, rbx
    call ncPrintReg
    call ncNewline
    popRegisters

    pushRegisters
    mov rdi, reg3
    call ncPrint
    mov rdi, rcx
    call ncPrintReg
    call ncNewline
    popRegisters

    pushRegisters
    mov rdi, reg4
    call ncPrint
    mov rdi, rdx
    call ncPrintReg
    call ncNewline
    popRegisters

    pushRegisters
    mov rbx, rdi
    mov rdi, reg5
    call ncPrint
    mov rdi, rbx
    call ncPrintReg
    call ncNewline
    popRegisters

    pushRegisters
    mov rdi, reg6
    call ncPrint
    mov rdi, rsi
    call ncPrintReg
    call ncNewline
    popRegisters

    pushRegisters
    mov rdi, reg7
    call ncPrint
    mov rdi, [rsp + 15*8]  ;; Change line to obtain rip value
    call ncPrintReg
    call ncNewline
    popRegisters

    pushRegisters
    mov rdi, reg8
    call ncPrint
    mov rdi, rsp
    call ncPrintReg
    call ncNewline
    popRegisters

    pushRegisters
    mov rdi, reg9
    call ncPrint
    mov rdi, rbp
    call ncPrintReg
    call ncNewline
    popRegisters
    ret

section .data
reg1 db "rax: ", 0
reg2 db "rbx: ", 0
reg3 db "rcx: ", 0
reg4 db "rdx: ", 0
reg5 db "rdi: ", 0
reg6 db "rsi: ", 0
reg7 db "rip: ", 0
reg8 db "rsp: ", 0
reg9 db "rbp: ", 0
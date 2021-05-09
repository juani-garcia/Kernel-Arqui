GLOBAL cpuVendor, accessClock, getKey

section .text
	
cpuVendor:
	push rbp
	mov rbp, rsp

	push rbx

	mov rax, 0
	cpuid


	mov [rdi], ebx
	mov [rdi + 4], edx
	mov [rdi + 8], ecx

	mov byte [rdi+13], 0

	mov rax, rdi

	pop rbx

	mov rsp, rbp
	pop rbp
	ret

accessClock: ; unsigned int accessClock(unsigned char mode)
	push rbp
	mov rbp, rsp

	mov al, dil
	out 70h, al
	xor rax, rax
	in al, 71h

	mov rsp, rbp
	pop rbp
	ret

getKey: ; unsigned int getKey();
	push rbp
	mov rbp, rsp
	xor rax, rax
.loop:    
	in al, 0x64       
    and al, 0x01       
    cmp al, 0
    je .loop
    in al, 0x60
       
    mov rsp, rbp
    pop rbp
    ret

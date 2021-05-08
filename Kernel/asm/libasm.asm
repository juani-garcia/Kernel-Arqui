GLOBAL cpuVendor, accessClock

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

	mov al, 0x09
	out 70h, al
	xor rax, rax
	in ax, 71h


	mov rsp, rbp
	pop rbp
	ret
GLOBAL cpuVendor, accessClock, print, getVideoModeInformation

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

print:
	push rbp
	mov rbp, rsp

	xor rax, rax
	int 80h

	mov rsp, rbp
	pop rbp
	ret

getVideoModeInformation:
	push rbp
	mov rbp, rsp

	mov ax, 0x4F01
	int 10h

	mov rsp, rbp
	pop rbp
	ret
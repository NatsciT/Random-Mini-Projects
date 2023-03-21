
	global sim_strlen
	global sim_strcpy


	section .text

; long sim_strlen(void* str);
sim_strlen:
	xor	rax, rax

__sim_strlen_loop:
	cmp	byte [rdi + rax], 0
	jz	__sim_strlen_end
	inc	rax
	jmp	__sim_strlen_loop

__sim_strlen_end:
	ret

	
; long sim_strcpy(void* src, void* des, size_t count);
sim_strcpy:
	push	rbx
	xor	rax, rax

__sim_strcpy_loop:
	cmp	rax, rdx
	je	__sim_strcpy_end
	mov	bl, byte [rdi + rax]
	mov	byte [rsi + rax], bl
	cmp	byte [rdi + rax], 0
	jz	__sim_strcpy_end
	inc	rax
	jmp	__sim_strcpy_loop

__sim_strcpy_end:
	pop	rbx
	ret

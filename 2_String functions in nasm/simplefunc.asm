
	global sim_strlen
	global sim_strcpy
	global sim_strcat

	section .text

; long sim_strlen(void* str);
; str == rdi
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
; src == rdi
; des == rsi
; count == rdx
sim_strcpy:
	xor	rax, rax
	dec	rdx
__sim_strcpy_loop:
	cmp	rax, rdx
	je	__sim_strcpy_end
	mov	r8b, byte [rdi + rax]
	mov	byte [rsi + rax], r8b
	cmp	r8b, 0
	jz	__sim_strcpy_end
	inc	rax
	jmp	__sim_strcpy_loop
__sim_strcpy_end:
	mov	byte [rsi + rax], 0
	ret


; long sim_strcat(void* des, void* str, size_t des_size);
; des == rdi
; str == rsi
; des_size == rdx
sim_strcat:
	mov	rax, rdi
	xor	rcx, rcx
	xor	r9, r9
	dec	rdx
__sim_strcat_loop1:
	cmp	byte [rdi + rcx], 0
	je	__sim_strcat_loop2
	inc	rcx
	jmp	__sim_strcat_loop1
__sim_strcat_loop2:
	cmp	rcx, rdx
	je	__sim_strcat_end
	mov	r8b, byte [rsi + r9]
	mov	byte [rdi + rcx], r8b
	cmp	byte [rsi + r9], 0
	je	__sim_strcat_end
	inc	rcx
	inc	r9
	jmp	__sim_strcat_loop2
__sim_strcat_end:
	mov	byte [rdi + rcx], 0
	ret

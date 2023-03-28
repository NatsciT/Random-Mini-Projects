; assemble with
; nasm -felf64 countdown.asm -o tmp.o && ld tmp.o -o countdown -e _main_start && rm tmp.o

	global _main_start

; syscalls
sys_read	equ	0
sys_write	equ	1
sys_exit	equ	60

; streams
sys_stdin	equ	0
sys_stdout	equ	1
sys_stderr	equ	2


	section .data
linebreak	db	10

displaymsg	db	"Write a number: "
displaymsg_len	equ	$ - displaymsg


	section .text
_main_start:
	push	rbp
	mov	rbp, rsp
	sub	rsp, 32

	mov	rax, sys_write
	mov	rdi, sys_stdout
	mov	rsi, displaymsg
	mov	rdx, displaymsg_len
	syscall

	mov	rax, sys_read
	mov	rdi, sys_stdin
	mov	rsi, rsp
	mov	rdx, 32
	syscall

	mov	word [rsp + 1], 0A00h

_main_loop:
	cmp	byte [rsp], '0'
	je	_main_exit

	mov	rax, sys_write
	mov	rdi, sys_stdout
	mov	rsi, rsp
	mov	rdx, 3
	syscall

	dec	byte [rsp]
	jmp	_main_loop

_main_exit:
	mov	rsp, rbp
	pop	rbp
	
	mov	rax, sys_exit
	xor	rdi, rdi
	syscall



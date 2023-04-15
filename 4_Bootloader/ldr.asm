bits 16

org 0x7c00

call	clear_screen

mov	si, msg
call	print_str
jmp	$

clear_screen:
	mov	ah, 0x00
	mov	al, 0x03
	int	0x10
	ret

print_str:
	lodsb
	or	al, al
	jz	__print_str_done
	mov	ah, 0x0E
	int	0x10
	jmp	print_str
__print_str_done:
	ret

msg	db	"Hello, world!", 0

times	510 - ($ - $$)	db 0
dw	0xAA55

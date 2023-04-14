bits 16

org 0x7c00

mov	si, msg
call	print_str
jmp	$

print_str:
	lodsb
	or	al, al
	jz	print_str.done
	mov	ah, 0x0E
	int	0x10
	jmp	print_str
print_str.done:
	ret

msg	db	"Hello, world!", 0

times	510 - ($ - $$)	db 0
dw	0xAA55

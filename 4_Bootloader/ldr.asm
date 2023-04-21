bits	16
org	0x7C00

main:
	call	clear_screen

	mov	si, msg
	call	print_str
main.L1:
	call	read_char
	test	al, al
	jz	main.L1

	mov	bh, 0x00
	mov	cx, 0x0001
	mov	bl, 0x0B
	call	print_char
	call	move_cursor

	jmp	main.L1



clear_screen:
	mov	ax, 0x0003
	int	0x10
	ret

print_str:
	lodsb
	or	al, al
	jz	print_str.L1
	mov	ah, 0x0E
	int	0x10
	jmp	print_str
print_str.L1:
	ret

; BH = page number CX = number of times to repeat AL = ASCII code BL = attrib
print_char:
	mov	ah, 0x09
	int	0x10
	ret

read_char:
	mov	ah, 0x00
	int	0x16
	ret

move_cursor:
	mov	ah, 0x03
	mov	bh, 0x00
	int	0x10
	add	dl, 0x01
	mov	ah, 0x02
	int	0x10
	ret



msg	db	"Hello, world!", 0xD, 0xA, 0

times	510 - ($ - $$)	db 0
dw	0xAA55

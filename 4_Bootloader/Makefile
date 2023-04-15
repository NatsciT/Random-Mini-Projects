MAKEFLAGS += --silent

ldr_asm := ldr.asm
ldr_bin := ldr.bin
flp := floppy.img

output := btldr.iso



all: clean floppy load iso

clean:
	rm -f ${output} ${flp} ${ldr_bin}

iso: ${flp} ${ldr_bin}
	genisoimage -o ${output} -V 'BTLDR' -input-charset iso8859-1 -b ${flp} -hide * .

load: ${flp}
	nasm -o ${ldr_bin} -fbin ldr.asm
	dd if=${ldr_bin} of=${flp} seek=0 count=1 conv=notrunc

floppy:
	dd if=/dev/zero of=${flp} bs=1024 count=1440

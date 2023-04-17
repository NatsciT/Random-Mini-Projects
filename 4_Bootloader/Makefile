MAKEFLAGS += --silent

ldr_asm := ldr.asm
ldr_bin := ldr.bin
flp := floppy.img

outdir := .


all: clean floppy load

clean:
	rm -f ${flp} ${ldr_bin}

load: ${flp}
	nasm -o ${ldr_bin} -fbin ldr.asm
	dd if=${ldr_bin} of=${outdir}/${flp} seek=0 count=1 conv=notrunc

floppy:
	dd if=/dev/zero of=${flp} bs=1024 count=1440

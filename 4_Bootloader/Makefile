MAKEFLAGS += --silent

asm := ldr.asm
bin := ldr.bin
flp := floppy.img

outdir := .


all: clean floppy loader

clean:
	rm -f ${flp} ${bin}

loader: ${outdir}/${flp}
	nasm -o ${bin} -fbin ${asm}
	dd if=${bin} of=${outdir}/${flp} seek=0 count=1 conv=notrunc

floppy:
	dd if=/dev/zero of=${outdir}/${flp} bs=1024 count=1440

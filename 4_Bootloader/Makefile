MAKEFLAGS += --silent

asm := ldr.asm
bin := ldr.bin
flp := floppy.img

outdir := .


all: clean floppy load

clean:
	rm -f ${flp} ${bin}

load: ${outdir}/${flp}
	nasm -o ${bin} -fbin ${asm}
	dd if=${bin} of=${outdir}/${flp} seek=0 count=1 conv=notrunc

floppy:
	dd if=/dev/zero of=${outdir}/${flp} bs=1024 count=1440

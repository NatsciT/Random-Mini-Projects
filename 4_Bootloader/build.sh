#!/bin/bash

dd if=/dev/zero of=floppy.img bs=1024 count=1440
dd if=ldr.bin of=floppy.img seek=0 count=1 conv=notrunc
genisoimage -o btldr.iso -V 'BTLDR' -input-charset iso8859-1 -b floppy.img -hide * . 

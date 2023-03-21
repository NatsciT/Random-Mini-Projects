#!/bin/bash
nasm -felf64 -o temp.o countdown.asm
ld -e _main_start -o countdown.out temp.o
rm temp.o

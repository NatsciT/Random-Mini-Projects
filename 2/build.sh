#!/bin/bash
nasm -felf64 -o temp.o simplefunc.asm
gcc -o simplefunc.out temp.o demo.c
rm temp.o

# MUIC - DPS - Laboratorio 1

## ejemplo1.c

Follow the instructions explained in the beginning of file ejemplo1.c for compiling with gcc and g++ (you can try also clang). 

## ejemplo2.c. Program Instrumentation

Find the memory errors presented in file ejemplo2 using gcc instrumentation option **AddressSanitizer (ASan)**.
Explain in this file each error.

Launching the example using the command line gcc ejemplo2.c -fsanitize=address -static-libasan -g
We get the next errors:


    Option 1: Everything is ok.

    Option 2: ==3907==ERROR: LeakSanitizer: detected memory leaks We don't use free to liberate the memory
        No se libera la memoria

    Option 3: ==3924==ERROR: AddressSanitizer: heap-use-after-free on address 0x60b0000000f0 at pc 0x55ef1f586e7d bp 0x7fffc2231260 sp 0x7fffc2230a08
        Se usa el free antes de acceder

    Option 4: ==3947==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x603000000022 at pc 0x56377f047e7d bp 0x7ffe3b6207c0 sp 0x7ffe3b61ff68
        El tamaño de la memoria que reservamos no es suficiente para el char, el \0 queda fuera.


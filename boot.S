.section .text
.global _start                                                                  
_start:
    ldr x0, =0x40010000
    mov sp, x0
    bl kernel_main

hang:
    b hang

.section .text
.global _start

_start:
    ldr x0, =0x40010000
    mov sp, x0                                                                                                                                                      // Kernel'i çağır                                                               bl kernel_main                                                              

hang:
    b hang

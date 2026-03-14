ENTRY(_start)

SECTIONS {
    . = 0x40000000;

    .text : {
        boot.o (.text)
        *(.text)
    }

    .data : {
        *(.data)
    }

    .bss : {
        *(.bss)
    }
}

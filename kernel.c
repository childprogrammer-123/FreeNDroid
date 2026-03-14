#define UART_BASE 0x09000000
#define UARTFR    0x09000018
#define RXFE      0x10

volatile unsigned int *uart    = (volatile unsigned int *)UART_BASE;
volatile unsigned int *uartfr  = (volatile unsigned int *)UARTFR;

void uart_putc(char c) {
    *uart = c;
}

void uart_print(const char *str) {                                                
  while (*str) {
        uart_putc(*str++);
    }
}

char uart_getc() {
    while (*uartfr & RXFE) {}
    return (char)(*uart);
}

void uart_readline(char *buf, int max) {
    int i = 0;
    char c;
    while (i < max - 1) {
        c = uart_getc();
        if (c == '\r' || c == '\n') {
            uart_putc('\n');
            break;
        }
        uart_putc(c);
        buf[i++] = c;
    }
    buf[i] = '\0';
}

void kernel_main() {
    uart_print("FreeNDroid v0.1 - Booting...\n");

    char buf[128];
    while (1) {
        uart_print("> ");
        uart_readline(buf, 128);
    }
}

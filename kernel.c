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

int str_eq(const char *a, const char *b) {
    while (*a && *b) {
        if (*a != *b) return 0;
        a++; b++;
    }
    return *a == *b;
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
        if (c == 127 || c == '\b') {
            if (i > 0) {
                i--;
                uart_putc('\b');
                uart_putc(' ');
                uart_putc('\b');
            } else {
                uart_putc('\a');
            }
            continue;
        }
        uart_putc(c);
        buf[i++] = c;
    }
    buf[i] = '\0';
}

void kernel_main() {
    uart_print("FreeNDroid v0.2 - Booting...\n");

    char buf[128];
    while (1) {
        uart_print("> ");
        uart_readline(buf, 128);
        if (str_eq(buf, "help")) {
            uart_print("This isn't a full OS. The developer will add something like bash command line for here. There are no commands on the command line right now.\n");
        }
    }
}

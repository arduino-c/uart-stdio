
#include <stdio.h>
#include <stdlib.h>
#include <uart/uart.h>

#define CRLF
#define ECHO


static void putchar(char c) {
	uart_write(&c, 1);
}

static char getchar() {
	char c;
	uart_read(&c, 1);
	return c;
}


static int uputc(char c, FILE *stream) {
#ifdef CRLF
	if (c == '\n')
		putchar('\r');
#endif
    putchar(c);
   return 0;
}

static int ugetc(FILE *stream) {
	int c = getchar();
	return c;
}

FILE uart_stdout = FDEV_SETUP_STREAM(uputc, NULL, _FDEV_SETUP_WRITE);
FILE uart_stdin = FDEV_SETUP_STREAM(NULL, ugetc, _FDEV_SETUP_READ);

void uart_stdio_init() {
	/* make uart_init(); before call */
	stdin = &uart_stdin;
	stdout = &uart_stdout;
	stderr = &uart_stdout;
}

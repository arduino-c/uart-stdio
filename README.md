UART STDIO
===

UART STDIO driver for ATmega328p (Arduino Uno rev3)

> This module need *UART* module present

###Usage

* Comment CRLF / ECHO (if need) macro in *uart_stdio.c* 
```c
#define CRLF
#define ECHO
```
* Write your code, e.g. in *main.c*

```c
...
#include <stdio.h>

int main() {
  printf("Hello World!\n");
  
  int i;
  i = 3;
  printf("variable i = %d\n", i);
  
  return 0;
}
```

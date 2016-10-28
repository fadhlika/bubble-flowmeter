#ifndef UART_H_
#define UART_H_
char usart_getchar( void ); 
void usart_init(void); 
void usart_putchar( char data ); 
void usart_pstr (char *s); 
unsigned char usart_kbhit(void); 
int usart_putchar_printf(char var, FILE *stream);
#endif

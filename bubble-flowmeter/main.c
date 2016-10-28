#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include "uart.h"

int ovf = 0;                            

int main(void){
	TCCR0B = (1 << CS00);
	EICRA = (1 << ISC11) | (1 << ISC01);
	PORTD = (1 << PORTD3) | (1 << PORTD2);
	EIMSK = (1 << INT0);
	TIMSK0 = (1 << 0);
	sei();
	usart_init();
	printf("starting\n");
	while(1){

	}
}

ISR (INT0_vect){
	EIMSK ^= (1 << INT1) | (1 << INT0);
	ovf = 0;
	TCNT0 = 0;
	printf("start timer \n");
}

ISR (INT1_vect){
	EIMSK ^= (1 << INT1);
	TIMSK0 = (1 << 0);
	unsigned int timer = TCNT0 + (ovf * 255);
	//float time = counter + ovf_;
	printf("%u \n", timer);
}

ISR (TIMER0_OVF_vect){
	ovf++;
}

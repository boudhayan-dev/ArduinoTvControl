/*
 * tv.c
 *
 *  Created on: May 28, 2017
 *      Author: gc
 */


#include"tv.h"

uint8_t rxbyte=0;
ISR(USART0_RX_vect)
{
	rxbyte=UDR0;
}
void uart_init()
{
	UBRR0H=(uint8_t)(BPS>>8);
		UBRR0L=(uint8_t)(BPS);
		//tx  AND RX
		UCSR0B |= (1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0);
		sei();   //cli(); for clearing
}
void uart_send(uint8_t senddata)
{
	while((UCSR0A & (1<<UDRE0))==0);
      UDR0=senddata;
}

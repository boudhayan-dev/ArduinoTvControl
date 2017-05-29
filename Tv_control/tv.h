/*
 * tv.h
 *
 *  Created on: May 28, 2017
 *      Author: gc
 */

#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>
#ifndef UART_H_
#define UART_H_
#define BR 9600
#define BPS ((F_CPU/(BR*16UL))-1)
void uart_init();
void uart_send(uint8_t senddata);
uint8_t uart_receive();


#endif /* UART_H_ */

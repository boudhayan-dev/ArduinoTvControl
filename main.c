/*
 * main.c
 *
 *  Created on: 19-May-2017
 *      Author: Admin
 */

#include<avr/io.h>
#include <avr/iomxx0_1.h>
#include<util/delay.h>
#include<avr/interrupt.h>
#define BAUD_RATE 9600
#define CF_CPU 16000000
#define BAUD_PRESCALE ((CF_CPU/(BAUD_RATE * 16UL))-1)
unsigned char rxbyte;
ISR(USART0_RX_vect)
{
	rxbyte=UDR0;
}
void init()
{
	UBRR0H = (unsigned char)(BAUD_PRESCALE >> 8); // used for storing MSB of calculated Baud Rate
	UBRR0L = (unsigned char)(BAUD_PRESCALE); // Used for storing the LSB of calculated Baud Rate
	UCSR0B |=(1<<3)|(1<<4)|(1<<RXCIE0);
	sei();//enabling interrupt
	//cli(); disable interrupt
}
void pwm_init()
{
		// Configure PB.7 as output pin
		DDRB |= (1<<PB5);
		// Clear o/p on Match and Fast PWM Mode
		TCCR1A |=  (1<<WGM11)  ;
		TCCR1B |=(1<<WGM12) | (1<<WGM13) | (1<<CS11);//WGM11/12/13 is used to set the fast pwm mode with max value stored in ICR1. CS01 is used to prescale the clock frequency to 16Mhz % 8 .
		ICR1 = 51; //26 microsec
		OCR1A = 26 ;
}

void inline pwm_off()
{

	TCCR1A &=  (~(1<<COM1A1));//Normal port operation
	PORTB &= (~(1<<PB5));//force the output as 0

}
void inline pwm_on()
{

	//TCNT1=0;
	TCCR1A |=  (1<<COM1A1);//pwm port operation

}

int main()
{

	TCCR1A=0;//clearing the registers in in initialization.
	TCCR1B=0;
	init();
	while(1)
	{
		if(rxbyte=='a')
		{
			pwm_init();

			pwm_off();
					_delay_ms(26);
					_delay_us(420);
					pwm_on();
					_delay_us(500);
					pwm_off();
					_delay_us(250);
					pwm_on();
					_delay_us(200);
					pwm_off();
					_delay_us(250);
					pwm_on();
					_delay_us(200);
					pwm_off();
					_delay_us(600);
					pwm_on();
					_delay_us(200);
					pwm_off();
					_delay_us(400);
					pwm_on();
					_delay_us(200);
					pwm_off();
					_delay_us(600);
					pwm_on();
					_delay_us(200);
					pwm_off();
					_delay_us(250);
					pwm_on();
					_delay_us(200);
					pwm_off();
					_delay_us(250);
					pwm_on();
					_delay_us(200);
					pwm_off();
					_delay_us(250);
					pwm_on();
					_delay_us(200);
					pwm_off();
					_delay_us(250);
					pwm_on();
					_delay_us(200);
					pwm_off();
					_delay_us(250);
					pwm_on();
					_delay_us(200);
					pwm_off();
					_delay_us(600);
					pwm_on();
					_delay_us(200);
					pwm_off();
					_delay_us(400);
					pwm_on();
					_delay_us(200);
					pwm_off();
					_delay_us(800);
					pwm_on();
					_delay_us(200);
					pwm_off();
					_delay_us(250);
					pwm_on();
					_delay_us(200);
					pwm_off();
					_delay_us(600);
					pwm_on();
					_delay_us(200);
					pwm_off();
					_delay_us(250);
					pwm_on();
					_delay_us(200);
					pwm_off();
					_delay_us(250);
					pwm_on();
					_delay_us(200);
					pwm_off();

					_delay_ms(26);
					_delay_us(420);
					pwm_on();
					_delay_us(500);
					pwm_off();
					_delay_us(250);
					pwm_on();
					_delay_us(200);
					pwm_off();
					_delay_us(250);
					pwm_on();
					_delay_us(200);
					pwm_off();
					_delay_us(600);
					pwm_on();
					_delay_us(200);
					pwm_off();
					_delay_us(400);
					pwm_on();
					_delay_us(200);
					pwm_off();
					_delay_us(600);
					pwm_on();
					_delay_us(200);
					pwm_off();
					_delay_us(250);
					pwm_on();
					_delay_us(200);
					pwm_off();
					_delay_us(250);
					pwm_on();
					_delay_us(200);
					pwm_off();
					_delay_us(250);
					pwm_on();
					_delay_us(200);
					pwm_off();
					_delay_us(250);
					pwm_on();
					_delay_us(200);
					pwm_off();
					_delay_us(250);
					pwm_on();
					_delay_us(200);
					pwm_off();
					_delay_us(600);
					pwm_on();
					_delay_us(200);
					pwm_off();
					_delay_us(400);
					pwm_on();
					_delay_us(200);
					pwm_off();
					_delay_us(800);
					pwm_on();
					_delay_us(200);
					pwm_off();
					_delay_us(250);
					pwm_on();
					_delay_us(200);
					pwm_off();
					_delay_us(600);
					pwm_on();
					_delay_us(200);
					pwm_off();
					_delay_us(250);
					pwm_on();
					_delay_us(200);
					pwm_off();
					_delay_us(250);
					pwm_on();
					_delay_us(200);


			TCCR1A &=  (~(1<<COM1A1));//switching off the pwm mode .
			PORTB &= (~(1<<PB5));
			_delay_ms(2500);
		}


	}

}

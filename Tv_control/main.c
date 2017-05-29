/*
 * main.c
 *
 *  Created on: May 28, 2017
 *      Author: gc
 */


#include"tv.h"
extern uint8_t rxbyte;
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
	//setup
	TCCR1A=0;//clearing the registers in in initialization.
	TCCR1B=0;
	uart_init();
	//LOOP
	while(1)
	{

		if(rxbyte=='a') //ch up
		{
			//uart_send('K');
			//_delay_ms(1000);
			//uart_send('a');
           //rxbyte=0;
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
			_delay_ms(3500);
		}
		else if(rxbyte=='b')  //ch down
		{
			pwm_init();
			pwm_off();
			_delay_ms(26);
					_delay_us(460);
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
					_delay_us(400);
					pwm_on();
					_delay_us(200);
					pwm_off();

					_delay_ms(26);
					_delay_us(460);
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
					_delay_us(400);
					pwm_on();
			_delay_us(200);

			TCCR1A &=  (~(1<<COM1A1));//switching off the pwm mode .
						PORTB &= (~(1<<PB5));
						_delay_ms(3500);
		}
		else if(rxbyte=='c')   //vol up
				{
			pwm_init();
			pwm_off();
			_delay_ms(41);
					_delay_us(700);
					pwm_on();
					_delay_ms(4);
					_delay_us(700);
					pwm_off();
					_delay_ms(4);
					_delay_us(500);
					pwm_on();

					_delay_us(600);
					pwm_off();
					_delay_ms(1);
							_delay_us(700);
					pwm_on();
					_delay_us(600);
					pwm_off();
					_delay_ms(1);
							_delay_us(700);
					pwm_on();
					_delay_us(600);
					pwm_off();
					_delay_ms(1);
							_delay_us(700);
					pwm_on();
					_delay_us(600);
					pwm_off();
					_delay_us(550);
					pwm_on();
					_delay_us(600);
					pwm_off();
					_delay_us(550);
					pwm_on();
					_delay_us(600);
					pwm_off();
					_delay_us(550);
					pwm_on();
					_delay_us(600);
					pwm_off();
					_delay_us(550);
					pwm_on();
					_delay_us(600);
					pwm_off();
					_delay_us(550);
					pwm_on();
					_delay_us(600);
					pwm_off();
					_delay_ms(1);
							_delay_us(700);
					pwm_on();
					_delay_us(600);
					pwm_off();
					_delay_ms(1);
					_delay_us(700);
					pwm_on();
					_delay_us(600);
					pwm_off();
					_delay_ms(1);
					_delay_us(700);
					pwm_on();
					_delay_us(600);
					pwm_off();
					_delay_us(550);
					pwm_on();
					_delay_us(600);
					pwm_off();
					_delay_us(550);
					pwm_on();
					_delay_us(600);
					pwm_off();
					_delay_us(550);
					pwm_on();
					_delay_us(600);
					pwm_off();
					_delay_us(550);
					pwm_on();
					_delay_us(600);
					pwm_off();
					_delay_us(550);
					pwm_on();
					_delay_us(600);

					pwm_off();
					_delay_ms(1);
					_delay_us(700);
					pwm_on();
					_delay_us(600);
					pwm_off();
					_delay_ms(1);
					_delay_us(700);
					pwm_on();
					_delay_us(600);
					pwm_off();
					_delay_ms(1);
					_delay_us(700);
					pwm_on();
					_delay_us(600);
					pwm_off();
					_delay_us(550);
					pwm_on();
					_delay_us(600);
					pwm_off();
					_delay_us(550);
					pwm_on();
					_delay_us(600);
					pwm_off();
					_delay_us(550);
					pwm_on();
					_delay_us(600);
					pwm_off();
					_delay_us(550);
					pwm_on();
					_delay_us(600);
					pwm_off();
					_delay_us(550);
					pwm_on();
					_delay_us(600);
					pwm_off();
					_delay_us(550);
					pwm_on();
					_delay_us(600);
					pwm_off();
					_delay_us(550);
					pwm_on();
					_delay_us(600);
					pwm_off();
					_delay_us(550);
					pwm_on();
					_delay_us(600);
					pwm_off();
					_delay_ms(1);
					_delay_us(700);
					pwm_on();
					_delay_us(600);
					pwm_off();
					_delay_ms(1);
					_delay_us(700);
					pwm_on();
					_delay_us(600);
					pwm_off();
					_delay_ms(1);
					_delay_us(700);
					pwm_on();
					_delay_us(600);
					pwm_off();
					_delay_ms(1);
					_delay_us(700);
					pwm_on();
					_delay_us(600);
					pwm_off();
					_delay_ms(1);
					_delay_us(700);
					pwm_on();
			_delay_us(600);

			TCCR1A &=  (~(1<<COM1A1));//switching off the pwm mode .
						PORTB &= (~(1<<PB5));
						_delay_ms(3500);
				}
		else if(rxbyte=='d')    //vol down
				{
			pwm_init();
			pwm_off();
			_delay_ms(16);
					//_delay_us(700);
					pwm_on();
					_delay_ms(4);
					_delay_us(700);
					pwm_off();
					_delay_ms(4);
					_delay_us(500);
					pwm_on();

					_delay_us(600);
					pwm_off();
					_delay_ms(1);
							_delay_us(700);
					pwm_on();
					_delay_us(600);
					pwm_off();
					_delay_ms(1);
							_delay_us(700);
					pwm_on();
					_delay_us(600);
					pwm_off();
					_delay_ms(1);
							_delay_us(700);
					pwm_on();
					_delay_us(600);
					pwm_off();
					_delay_us(550);
					pwm_on();
					_delay_us(600);
					pwm_off();
					_delay_us(550);
					pwm_on();
					_delay_us(600);
					pwm_off();
					_delay_us(550);
					pwm_on();
					_delay_us(600);
					pwm_off();
					_delay_us(550);
					pwm_on();
					_delay_us(600);
					pwm_off();
					_delay_us(550);
					pwm_on();
					_delay_us(600);
					pwm_off();
					_delay_ms(1);
							_delay_us(700);
					pwm_on();
					_delay_us(600);
					pwm_off();
					_delay_ms(1);
					_delay_us(700);
					pwm_on();
					_delay_us(600);
					pwm_off();
					_delay_ms(1);
					_delay_us(700);
					pwm_on();
					_delay_us(600);
					pwm_off();
					_delay_us(550);
					pwm_on();
					_delay_us(600);
					pwm_off();
					_delay_us(550);
					pwm_on();
					_delay_us(600);
					pwm_off();
					_delay_us(550);
					pwm_on();
					_delay_us(600);
					pwm_off();
					_delay_us(550);
					pwm_on();
					_delay_us(600);
					pwm_off();
					_delay_us(550);
					pwm_on();
					_delay_us(600);

					pwm_off();
					_delay_ms(1);
					_delay_us(700);
					pwm_on();
					_delay_us(600);
					pwm_off();
					_delay_ms(1);
					_delay_us(700);
					pwm_on();
					_delay_us(600);
					pwm_off();
					//_delay_ms(1);
					_delay_us(550);
					pwm_on();
					_delay_us(600);
					pwm_off();
					_delay_ms(1);
					_delay_us(700);
					pwm_on();
					_delay_us(600);
					pwm_off();
					_delay_us(550);
					pwm_on();
					_delay_us(600);
					pwm_off();
					_delay_us(550);
					pwm_on();
					_delay_us(600);
					pwm_off();
					_delay_us(550);
					pwm_on();
					_delay_us(600);
					pwm_off();
					_delay_us(550);
					pwm_on();
					_delay_us(600);
					pwm_off();
					_delay_us(550);
					pwm_on();
					_delay_us(600);
					pwm_off();
					_delay_us(550);
					pwm_on();
					_delay_us(600);
					pwm_off();
					_delay_ms(1);
					_delay_us(700);
					pwm_on();
					_delay_us(600);
					pwm_off();
					//_delay_ms(1);
					_delay_us(550);
					pwm_on();
					_delay_us(600);
					pwm_off();
					_delay_ms(1);
					_delay_us(700);
					pwm_on();
					_delay_us(600);
					pwm_off();
					_delay_ms(1);
					_delay_us(700);
					pwm_on();
					_delay_us(600);
					pwm_off();
					_delay_ms(1);
					_delay_us(700);
					pwm_on();
					_delay_us(600);
					pwm_off();
					_delay_ms(1);
					_delay_us(700);
					pwm_on();
			_delay_us(600);

			TCCR1A &=  (~(1<<COM1A1));//switching off the pwm mode .
						PORTB &= (~(1<<PB5));
						_delay_ms(3500);
				}
		else if(rxbyte=='p')   //power on/off
				{
			pwm_init();
			pwm_off();
			_delay_ms(48);
					_delay_us(400);
					pwm_on();
					//_delay_ms(4);
					_delay_us(500);
					pwm_off();
					//_delay_ms(4);
					_delay_us(250);
					pwm_on();

					_delay_us(200);
					pwm_off();
					//_delay_ms(1);
							_delay_us(250);
					pwm_on();
					_delay_us(200);
					pwm_off();
					//_delay_ms(1);
							_delay_us(600);
					pwm_on();
					_delay_us(200);
					pwm_off();
					//_delay_ms(1);
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
					//_delay_ms(1);
					_delay_us(600);
					pwm_on();
					_delay_us(200);
					pwm_off();
					//_delay_ms(1);
					_delay_us(600);
					pwm_on();
					_delay_us(200);
					pwm_off();
					//_delay_ms(1);
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
					_delay_us(250);
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
							_delay_ms(26);
							//_delay_us(700);
							pwm_on();
							//_delay_ms(4);
							_delay_us(500);
							pwm_off();
							//_delay_ms(4);
							_delay_us(250);
							pwm_on();

							_delay_us(200);
							pwm_off();
							//_delay_ms(1);
									_delay_us(250);
							pwm_on();
							_delay_us(200);
							pwm_off();
							//_delay_ms(1);
									_delay_us(600);
							pwm_on();
							_delay_us(200);
							pwm_off();
							//_delay_ms(1);
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
							//_delay_ms(1);
									_delay_us(600);
							pwm_on();
							_delay_us(200);
							pwm_off();
							//_delay_ms(1);
							_delay_us(600);
							pwm_on();
							_delay_us(200);
							pwm_off();
							//_delay_ms(1);
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
							_delay_us(250);
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

			TCCR1A &=  (~(1<<COM1A1));//switching off the pwm mode .
						PORTB &= (~(1<<PB5));
						_delay_ms(3500);
				}
		else    //stop
		{
			_delay_ms(3500);
		}
		uart_send(rxbyte);

		//while(UCSR0A & (1<<TXC0)==0);
		//CLEAR THE FLAG
		//UCSR0A |=(1<<TXC0);
	}
}

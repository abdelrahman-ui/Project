/*
 * T0_FPWM.c
 *
 * Created: 11/21/2020 8:12:26 AM
 * Author : Abdelrahman_Magdy
 */ 
#define F_CPU 16000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define		Dir_1	5
#define		Dir_2	4
#define		EN		3
int main(void)
{
	
	//Dir 
	DDRB|=(1<<Dir_1)|(1<<Dir_2)|(1<<EN);
    //The Mode of The Timer 0
	//PORT
	PORTB|=(1<<Dir_1);
	//FPWM & No prescaler & NON_inerting & INVERTING 
	TCCR0|=(1<<WGM00)|(1<<WGM01)|(1<<COM01)|(1<<CS00)|(1<<COM00);
	//Enable Interrput 
	TIMSK|=(1<<TOV0)|(1<<OCIE0);
	//Global Isr
	sei();
	OCR0=255;
    while (1) 
    {
		for (int i=127;i<255;i++)
		{
			OCR0=i; //oc0 pin = LED GO HIGH
			_delay_ms(5);
		}
		for (int i=255;i>127;i--)
		{
			OCR0=i; //oc0 pin = LED
			_delay_ms(5);
		}

    }
}


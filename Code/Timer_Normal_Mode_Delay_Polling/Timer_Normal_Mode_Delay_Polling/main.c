/*
 * Timer_Normal_Mode_Delay_Polling.c
 *
 * Created: 11/20/2020 5:29:43 AM
 * Author : Abdelrahman_Magdy
 */ 

#define F_CPU 16000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
volatile unsigned char count0 = 0 ;
volatile unsigned char count1 = 0 ;
volatile unsigned char count2 = 0 ;
int main(void)
{
	DDRD|=(1<<5)|(1<<6)|(1<<7);
	//Prescaler
	TCCR0|=(1<<CS01)|(1<<CS00);
	//Enable ISR
	//TIMSK|=(1<<TOIE0);
	//global
	//sei();
	/* Replace with your application code */
	while (1)
	{
		while(!(TIFR & (1<<TOV0)));
		TIFR|=(1<<TOV0);				//CLEAR FLAG
		count0++;
		count1++;
		count2++;
		if(count0==200)
		{
			PORTD^=(1<<PIND5);
		//	_delay_ms(90);
			count0=0;
		}
		if(count1==250)
		{
			PORTD^=(1<<PIND6);
			//_delay_ms(90);
			count1=0;
		}
		if(count2==100)
		{
			PORTD^=(1<<PIND7);
		//	_delay_ms(90);
			count2=0;
		}
		
	}

}
/*
ISR(TIMER0_OVF_vect)
{
	count0++;
	count1++;
	count2++;
	
}*/
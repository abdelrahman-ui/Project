/*
 * ISR_INT0_LED.c
 *
 * Created: 11/18/2020 7:47:45 AM
 * Author : Abdelrahman_Magdy
 */ 

#define  F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


#define LED 7
volatile unsigned char flag=0 ;
int main(void)
{
	DDRD|=(1<<LED);
	//CONFIGUR INT0
		GICR|=(1<<INT0);				//ENABLE INTO
    //TYPE OF ISR
	 MCUCR|=(1<<ISC00)|(1<<ISC01);       //RISING EDGE
	 //ENABLE GLOBAL ISR
	  sei();
	  PORTD&=~(1<<LED);
    while (1) 
    {
		if (flag==1)
		{
			PORTD^=(1<<LED);
			_delay_ms(100);
			flag=0;
		}
		
		
			
    }
}

ISR (INT0_vect)
{
	flag ++;
}
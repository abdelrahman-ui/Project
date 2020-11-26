/*
 * Timer0_CTC_Mode.c
 *
 * Created: 11/20/2020 11:01:10 AM
 * Author : Abdelrahman_Magdy
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
volatile unsigned short OC[4]={10,100,170,220,};
volatile unsigned short	OCR_COUNT=0;
int main(void)
{
	//Dir of PB3
	DDRB|=(1<<PB3);
	//CTC Mode &	NOPRESCALER  &	 TOGGLE 0C0 ON COMPARE
    TCCR0|=(1<<WGM01)|(1<<COM00)|(1<<CS00)	;
	//Interrput
	TIMSK|=(1<<OCIE0)|(1<<TOV0);
	sei();			
	OCR0=OC[0] ;
    while (1) 
    {
		
	}
}


ISR(TIMER0_COMP_vect)
{
	OCR_COUNT++;
	if(OCR_COUNT  <  4    )
	{
		OCR0=OC[OCR_COUNT];
	}
	else{
		OCR_COUNT =0;
		OCR0=OC[OCR_COUNT];
	}
	
}
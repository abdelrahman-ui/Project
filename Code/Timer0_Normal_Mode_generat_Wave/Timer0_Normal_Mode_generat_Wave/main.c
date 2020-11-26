/*
 * Timer0_Normal_Mode_generat_Wave.c
 *
 * Created: 11/20/2020 9:33:35 AM
 * Author : Abdelrahman_Magdy
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


volatile unsigned char OVF_Count =0;
volatile unsigned short OCR_Count =0;			//OCR
volatile unsigned short OCR_Count2 =0;
#define LED_5	5
#define LED_6	6
#define LED_7	7

int main(void)
{
	//The OC0 must be Set dir out if you want To Generat Wave
	DDRB|=(1<<PB3)  ;
	//To be toggle	& No Prescaler
     TCCR0|=(1<<COM00)|(1<<CS00)|(1<<CS02);								
	//Enable the flag ISR of ovf And of ocr flag
	TIMSK|=(1<<OCIE0);							//NOT Need here 
	//Global isr 
	sei();
	//put the number of puls which i need to be combared with tcnt
	OCR0 = 127	 ;							//0:127=128
    while (1) 
    {
		/*if(OVF_Count==976)
		{
			TIMSK|=(1<<OCIE0);
		}*/
		if (OCR_Count==977)        //m4 rady y3mel 977 leh m4 3aref
		{
			PORTD ^=(1<<LED_7);
			OCR_Count=0;
		}
		if (OCR_Count2==((10*977)/2))        //m4 rady y3mel 977 leh m4 3aref
		{
			PORTD ^=(1<<LED_5);
			OCR_Count2=0;
		}
    }
}


ISR(TIMER0_COMP_vect)
{
	OCR_Count++;
	OCR_Count2++;
	PORTD^=(1<<LED_6); //debugging by led if it come in to comp or not
	
}
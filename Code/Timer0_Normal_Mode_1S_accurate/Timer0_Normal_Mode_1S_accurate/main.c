/*
 * Timer0_Normal_Mode_1S_accurate.c
 *
 * Created: 11/20/2020 6:37:41 AM
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
/*#define prescaler 64
#define TIME     (64/F_CPU)
#define count_in_sec (1/TIME)
#define Complet_Reg   (count_in_sec/256)    //976.5*/
int main(void)
{
	DDRD|=(1<<LED_5)|(1<<LED_6)|(1<<LED_7);
	// Prescaler (16000000/64)
    TCCR0|=(1<<CS01)|(1<<CS00);						
	//enable the flag isr of ovf And of ocr flag
	//TIMSK|=(1<<TOIE0);
	TIMSK|=(1<<OCIE0);
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
			//OVF_Count =0;
			//_delay_ms(100);
			OCR_Count=0;
		}
		if (OCR_Count2==((10*977)/2))        //m4 rady y3mel 977 leh m4 3aref
		{
			PORTD ^=(1<<LED_5);
			//OVF_Count =0;
			//_delay_ms(100);
			OCR_Count2=0;
		}
    }
}

/*ISR(TIMER0_OVF_vect)
{
	OVF_Count++;
	PORTD^=(1<<LED_7);
	_delay_ms(100);
}
*/
ISR(TIMER0_COMP_vect)
{
	OCR_Count++;
	OCR_Count2++;
	PORTD^=(1<<LED_6); //debugging by led if it come in to comp or not
	
}
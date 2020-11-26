/*
 * 7segement_int0.c
 *
 * Created: 11/19/2020 12:21:41 AM
 * Author : Abdelrahman_Magdy
 */ 

#define  F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>



unsigned char seg[]={0b0111111,0b0000110,0b1011011,0b1001111,0b1100110,0b1101101,0b1111101,0b1001111,0b1111111,0b1101111};
volatile unsigned char count=0 ;
volatile unsigned char i=0;
int main(void)
{
	DDRC|=0xff;
	//CONFIGUR INT0
	GICR|=(1<<INT0);				//ENABLE INTO
	//TYPE OF ISR
	MCUCR|=(1<<ISC10)|(1<<ISC11);       //RISING EDGE
	//ENABLE GLOBAL ISR
	sei();
	
	while (1)
	{
				
		//while((PIND&0x02)==0x01);        //do no thing
		switch(count)
		{
			case 0:
			PORTC=seg[0];
			
			_delay_ms(100);
			break;
			case 1:
			PORTC=seg[1];
			
			_delay_ms(100);
			break;
			
			case 2:
			PORTC=seg[2];
			
			_delay_ms(100);
			break;
			case 3:
			PORTC=seg[3];
			
			_delay_ms(100);
			break;
			case 4:
			PORTC=seg[4];
			
			_delay_ms(100);
			break;
			case 5:
			PORTC=seg[5];
			
			_delay_ms(100);
			break;
			case 6:
			PORTC=seg[6];
			
			_delay_ms(100);
			
			break;
			case 7:
			PORTC=seg[7];
			
			_delay_ms(100);
			break;
			case 8:
			PORTC=seg[8];
			
			_delay_ms(100);
			break;
			case 9:
			PORTC=seg[9];
			
			_delay_ms(100);
			count=0;
			break;
			
			
		}
	}
}

ISR (INT0_vect)
{
	count ++;
}
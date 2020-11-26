/*
 * traffic_external_isr.c
 *
 * Created: 11/19/2020 12:53:18 AM
 * Author : Abdelrahman_Magdy
 */ 

#define  F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


#define LED_RED		7
#define LED_YELLOW	6
#define LED_GREEN	5

#define RED		0
#define YELLOW	1
#define GREEN	2

unsigned char count ;
unsigned char state ;


//Prototype
void RED_Blinking();
void RED_Off();
void YELLOW_Blinking();
void YELLOW_Off();
void GREEN_Blinking();
void GREEN_Off();
//ISR
ISR (INT0_vect)
{
	unsigned char pending_time=0;
	if(state==GREEN)
	{
		pending_time=15-count;
		while(count<pending_time)
		{
			GREEN_Blinking();
			count++;
		}
		GREEN_Off();
		count=8;
	}
}


int main(void)
{
    //CONFIGUR INT0
    GICR|=(1<<INT0);				//ENABLE INTO
    //TYPE OF ISR
    MCUCR|=(1<<ISC01)|(1<<ISC00);       //RISING EDGE
    //ENABLE GLOBAL ISR
    sei();
	
	DDRA|=0XFF;
	
	count=0;
	state=0;
	 
    while (1) 
    {
		switch(state)
		{
			case (RED):
				while(count<15)
				{
					RED_Blinking();
					count++;
				}
				RED_Off();
				count=0;
				state=GREEN;
			break;
			
			case (GREEN):
				while(count<7)
				{
					GREEN_Blinking();
					count++;
				}
				GREEN_Off();
				count=0;
				state=YELLOW;
			break;
				
			case (YELLOW):
				while(count<3)
				{
					YELLOW_Blinking();
					count++;
				}
				YELLOW_Off();
				count=0;
				state=RED;
			break;					
			
		}
    }
}


void RED_Blinking()
{
	PORTA|=(1<<LED_RED);
	_delay_ms(100);
	PORTA&=~(1<<LED_RED);
	_delay_ms(100);
}
void RED_Off()
{
	PORTA&=~(1<<LED_RED);
}


  
void GREEN_Blinking()
{
	PORTA|=(1<<LED_GREEN);
	_delay_ms(100);
	PORTA&=~(1<<LED_GREEN);
	_delay_ms(100);
}
void GREEN_Off()
{
	PORTA&=~(1<<LED_GREEN);
}



void YELLOW_Blinking()
{
	PORTA|=(1<<LED_YELLOW);
	_delay_ms(100);
	PORTA&=~(1<<LED_YELLOW);
	_delay_ms(100);
}
void YELLOW_Off()
{
	PORTA&=~(1<<LED_YELLOW);
}
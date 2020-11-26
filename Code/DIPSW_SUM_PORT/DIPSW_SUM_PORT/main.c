/*
 * DIPSW_SUM_PORT.c
 *
 * Created: 11/4/2020 11:00:34 PM
 * Author : User™
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h> 

int main(void)
{
	DDRA|=0X00;					//Input Direction Port
	DDRB|=0X00;					//Input Direction Port
	DDRC|=0XFF;					//Ouput Direction Port
	PORTA=PORTC=PORTB=0x00;	    //Initialize Port by zero
    while (1) 
    {
		PORTC=0x00;	
		PORTC=PINB+PINA;
		_delay_ms(500);
	  
		
    }
}


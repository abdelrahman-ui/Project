/*
 * Magic_button.c
 *
 * Created: 11/6/2020 1:35:08 AM
 * Author : User™
 */ 

#include <avr/io.h>
#include "bit_math.h"
#include <util/delay.h>
static count =0;
int main(void)
{
    SET_BIT(DDRC,0);
	CLR_BIT(DDRA,0);
	SET_BIT(DDRD,0);
	 while (1)
    {
		
		 while(GET_BIT(PINA,0)==0);
			_delay_ms(70);
			count++;
		switch(count)
		{
		  case 1:
		  
			TOGGLE_BIT(PORTC,0);
			_delay_ms(1000);
			TOGGLE_BIT(PORTC,0);
			break;
			
		  case 2:
			
			TOGGLE_BIT(PORTD,0);
			_delay_ms(1000);
			TOGGLE_BIT(PORTC,0);
			count=0;
		  break;
			
    }
	 while(GET_BIT(PINA,0)==1);
}
}


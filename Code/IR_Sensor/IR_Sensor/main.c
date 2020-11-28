/*
 * IR_Sensor.c
 *
 * Created: 11/28/2020 10:01:39 AM
 * Author : Abdelrahman_Magdy
 */ 

#define F_CPU 16000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "LCD_4_BIT.h"
#include "bit_math.h"

int main(void)
{
    LCD_Init();
	CLR_BIT(DDRD,0);
    while (1) 
    {
		if(GET_BIT(PIND,0)==1)
		{
			LCD_Clear();
			LCD_Command(0x80);
			LCD_String("IR Sense ");
			LCD_Command(0xc0);
			LCD_String("obstacle");
			_delay_ms(2000);	
			
		}
		else
		{
			LCD_Clear();
			LCD_Command(0x80);
			LCD_String("IR Sense ");
			LCD_Command(0xc0);
			LCD_String("Nothing");		
			_delay_ms(2000);	
			
		}
    }
}


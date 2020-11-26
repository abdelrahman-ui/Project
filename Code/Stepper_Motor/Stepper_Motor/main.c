/*
 * Stepper_Motor.c
 *
 * Created: 11/25/2020 10:18:21 AM
 * Author : Abdelrahman_Magdy
 */ 

#define  F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define Stepper_Leg_3	PC3
#define Stepper_Leg_4	PC4
#define Stepper_Leg_5	PC5
#define Stepper_Leg_6	PC6 

#define EN_1		4
#define EN_2		5
void Stepper_Motor(unsigned char Mode);
int main(void)
{
    DDRC|=(1<<Stepper_Leg_6)|(1<<Stepper_Leg_5)|(1<<Stepper_Leg_3)|(1<<Stepper_Leg_4);
	DDRD|=(1<<EN_1)|(1<<EN_2);
	PORTD|=(1<<EN_1)|(1<<EN_2);
    while (1) 
    {
		_delay_ms(2000);
		Stepper_Motor(1);
		_delay_ms(2000);
		PORTC|=0x00;
		Stepper_Motor(2);
		_delay_ms(2000);
		PORTC|=0x00;
		Stepper_Motor(3);
		_delay_ms(2000);
		PORTC|=0x00;
		Stepper_Motor(4);
		_delay_ms(2000);
		PORTC|=0x00;				
		
    }
}


void Stepper_Motor(unsigned char Mode)
{
	switch(Mode)
	{
		case 1 :
		    	PORTC |= (1<<Stepper_Leg_5)|(1<<Stepper_Leg_6);
		    	PORTC &= ~(1<<Stepper_Leg_3)|(1<<Stepper_Leg_4);
				
		break ;
		
		case 2 :
				PORTC |= (1<<Stepper_Leg_5)|(1<<Stepper_Leg_4);
				PORTC &= ~(1<<Stepper_Leg_6)&(1<<Stepper_Leg_3);
		break ;
		
    	case 3 :
				PORTC |= (1<<Stepper_Leg_3)|(1<<Stepper_Leg_4);
				PORTC &= ~(1<<Stepper_Leg_5)|(1<<Stepper_Leg_6);		
		break ;
		
		case 4 :
				PORTC |= (1<<Stepper_Leg_3)|(1<<Stepper_Leg_6);
				PORTC &= ~(1<<Stepper_Leg_4)|(1<<Stepper_Leg_5);					
		break ;		
	}
}
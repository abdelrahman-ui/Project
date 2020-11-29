/*
 * Stepper.c
 *
 * Created: 11/30/2020 12:44:52 AM
 *  Author: Abdelrahman_Magdy
 */ 

#include "Stepper.h"
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

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
		PORTC &= ~(1<<Stepper_Leg_6)|(1<<Stepper_Leg_3);
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
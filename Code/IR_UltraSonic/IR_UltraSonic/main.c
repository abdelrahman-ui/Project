/*
 * IR_UltraSonic.c
 *
 * Created: 11/28/2020 11:30:29 AM
 * Author : Abdelrahman_Magdy
 */ 


#define F_CPU 16000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "LCD_4_BIT.h"
#include "bit_math.h"

#define   Safty_Rang        60
#define   Trigger		    PD7
#define   Air_Velocity      34600		//AT real 34000
#define   PIR			    PD0

#define  Free_Region		PC1
#define  Dangerous_Region   PC0

void PIR_FUN();
int main(void)
{
		
		 LCD_Init();
		 unsigned short Rising_edage,Falling_edage,Still_on_to,Distance;
		// float Distance;
		  DDRD|=(1<<Trigger);
		  char Dis[10];
		  DDRD&=~(1<<PIR);
    while (1) 
    {
		LCD_Clear();
		TCCR1A=0;			/* Set all bit to zero Normal operation */
		DDRC|=(1<<Dangerous_Region)|(1<<Free_Region);			//Dir_LeD
		TIFR=(1<<ICF1);				//		ClearThe Flag Of ICF1
		PORTD |=(1<<Trigger);		//		Dir of OC2 out
		_delay_ms(20);
		PORTD &=~(1<<Trigger);		//		Dir of OC2 out of
		// Noise Canceler & Input Edge Select Rising edage & No Prescaler 
		TCCR1B|=0XC1;				//(1<<ICNC1)|(1<<ICES1)|(1<<CS10);
		//Poilling
		while((TIFR&(1<<ICF1)) ==0);
		//Save The Value of Capture REG
		Rising_edage=ICR1;
		/* Clear ICF flag */
		TIFR=(1<<ICF1);
		// Noise Canceler & Input Edge Select falling edage & No Prescaler
		TCCR1B=0X81;							//(1<<ICNC1)|(1<<CS10);
		 while ((TIFR&(1<<ICF1)) == 0);
		 Falling_edage=ICR1;
		 TIFR = (1<<ICF1);  	/* Clear ICF flag */
		 TCNT1=0;				//
		 TCCR1B = 0;  		/* Stop the timer */
		 Still_on_to=(Falling_edage-Rising_edage);
		 Distance=((Still_on_to*Air_Velocity)/(F_CPU*2));
		 sprintf(Dis,"%d",Distance);		//Convert To String
		 PIR_FUN();
		 if(Distance>=Safty_Rang )       //>=60
		 {
			 LCD_Clear();
			LCD_String("ULtrasonic");
			 _delay_ms(1000);
			 LCD_Clear();
			 LCD_String("Distance = ");
			 LCD_String(Dis);
			 LCD_String("cm");
			 LCD_Command(0XC0);
			 LCD_String("Free_Region");
			 SET_BIT(PORTC,Free_Region);
			// PORTC|=(1<<Free_Region);
			 _delay_ms(1000);
			 CLR_BIT(PORTC,Free_Region);
			// PORTC&=~(1<<Free_Region);
		 }
		 else
		 {
			  LCD_Clear();
		      LCD_String("ULtrasonic");
		      _delay_ms(1000);			 
			  LCD_Clear();
			  LCD_String("Distance = ");
	    	 /* LCD_Char((Distance/10)+48);
			  LCD_Char((Distance%10)+48);*/
			  LCD_String(Dis);
			  LCD_String("cm");
			  LCD_Command(0xc0);
		      LCD_String("Denger_Region");
			  PORTC|=(1<<Dangerous_Region);
			  _delay_ms(1000);
			  PORTC&=~(1<<Dangerous_Region);			  
			 
		 }
		 
    }
}
void PIR_FUN()
{
	if(GET_BIT(PIND,0)==1)
	{
		LCD_Clear();
		LCD_Command(0x80);
		LCD_String("IR Sense ");
		LCD_Command(0xc0);
		LCD_String("there is obstacle");
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
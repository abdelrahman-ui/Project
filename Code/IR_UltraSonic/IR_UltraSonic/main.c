
#define F_CPU 16000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "LCD_4_BIT.h"
#include "bit_math.h"

#define   Safty_Rang        68
#define   Trigger		    PD7
#define   Air_Velocity      34600		//AT real 34000
#define   PIR			    PD2

#define Front_LED_1		PC0
#define Front_LED_2		PC1
#define Back_LED_1		PC4
#define BACK_LED_2		PC5
#define Right_LED		PC2
#define Left_LED		PC3
#define PIR_LED_1		PC6
#define PIR_LED_2		PC7



void PIR_Sensor();

unsigned short Rising_edage,Falling_edage,Still_on_to,Distance=0;
char Dis[10];


int main(void)
{
	
	LCD_Init();
	DDRD|=(1<<Trigger);
	DDRD&=~(1<<PIR);
	DDRC|=0XFF;
	while (1)
	{
		PORTC|=(1<<Front_LED_1)|(1<<Front_LED_2);
		//UltraSonic
		TCCR1A=0;			/* Set all bit to zero Normal operation */
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
		
		
		
		if(Distance>=Safty_Rang )       //>=68
		{
			
			PORTC=0x03;
			LCD_Clear();
			LCD_String("ULtrasonic");
			_delay_ms(500);
			LCD_Clear();
			LCD_String("Distance = ");
			LCD_String(Dis);
			LCD_String("cm");
			LCD_Command(0XC0);
			LCD_String("Free_Region");
			_delay_ms(500);

		}
		else
		{
			
			LCD_Clear();
			LCD_String("ULtrasonic");
			_delay_ms(500);
			PORTC|=(1<<Back_LED_1)|(1<<BACK_LED_2)|(1<<Left_LED)|(1<<Right_LED);
			LCD_Clear();
			PORTC&=~(1<<Left_LED);
			PORTC&=~(1<<Right_LED);
			LCD_String("Distance = ");
			LCD_String(Dis);															/* LCD_Char((Distance/10)+48);*/
			LCD_String("cm");															 /*LCD_Char((Distance%10)+48);*/
			LCD_Command(0xc0);
			LCD_String("Denger_Region");
			PORTC|=(1<<Left_LED);
			PORTC|=(1<<Right_LED);
			_delay_ms(500);
			PORTC&=~(1<<Left_LED);
			PORTC&=~(1<<Right_LED);
			_delay_ms(500)	;
			
			
		}
		PIR_Sensor();
	}
}


void PIR_Sensor()
{
	if(GET_BIT(PIND,PIR)==1)
	{
		PORTC|=(1<<PIR_LED_1);
		PORTC&=~(1<<PIR_LED_2);
		LCD_Clear();
		LCD_Command(0x80);
		LCD_String("IR Sense ");
		LCD_Command(0xc0);
		LCD_String("there is obstacle");
		_delay_ms(500);
		PORTC^=(1<<Left_LED);
		PORTC^=(1<<Right_LED);
		
	}
	else
	{
		PORTC|=(1<<PIR_LED_2);
		PORTC&=~(1<<PIR_LED_1);
		LCD_Clear();
		LCD_Command(0x80);
		LCD_String("IR Sense ");
		LCD_Command(0xc0);
		LCD_String("Nothing");
		_delay_ms(500);
		_delay_ms(200);
		
	}
}
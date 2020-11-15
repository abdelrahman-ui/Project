/*
 * ADC_FAN_LM35.c
 *
 * Created: 11/15/2020 1:19:26 AM
 * Author : Abdelrahman_Magdy
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <stdio.h>
#include "LCD_4_BIT.h"

#define  Red_LED  PIND0
#define  WHITE_LED  PIND1
#define  Fan  PIND2

#define degree_sysmbol 0xdf
#define ADMUX0		0  //ADC1

//Prototype
void ADC_Init();
unsigned int ADC_Read(char channel);

int main()
{
	char Temperature[10],voltage[10];
	float celsius,volt;
	
	DDRD|=(1<<Fan)|(1<<WHITE_LED)|(1<<Red_LED);
	LCD_Init();                 /* initialize 16x2 LCD*/
	ADC_Init();                 /* initialize ADC*/
	LCD_Clear();
	while(1)
	{
		LCD_Clear();
		LCD_Command(0x80);		/* Go to 1st line*/
		//LCD_String_xy(0,0,"Temperature");
		celsius = (ADC_Read(0)*2.5);
		celsius = (celsius/10.00); //equation of temperature sensor
		sprintf(Temperature,"%d%cC",(int)celsius, degree_sysmbol);               // convert integer value to ASCII string
		LCD_String("Temperature= ");
		LCD_String(Temperature);                // send string data for printing
		_delay_ms(100);
		/*
		memset(Temperature,0,10);
		*/
		if(celsius>30)
		{
			
			PORTD&=~(1<<WHITE_LED);		//WHITE LED OFF	
			LCD_Clear();
			LCD_String("RED LED ON");
			PORTD|=(1<<Red_LED);
			LCD_Command(0XC0);
			LCD_String(" FAN ON");
			PORTD|=(1<<Fan);
			
		}
		if(celsius<30)
		{
			PORTD&=~(1<<Red_LED);			//RED LED OFF
			LCD_Clear();
			LCD_String("WHite LED  ON");
			PORTD|=(1<<WHITE_LED);
			LCD_Command(0XC0);
			LCD_String(" FAN OFF");
			PORTD&=~(1<<Fan);
																							//FAN OFF I CAN NOT
			
		}
		//Read The frist voltage
		LCD_Clear();
		LCD_Command(0x80);		// Go to 1st line
		volt = (ADC_Read(1)*5);
		volt =volt/255.0;
		sprintf(voltage,"%d",volt);               // convert integer value to ASCII string
		LCD_String("volT(1)= ");
		LCD_String(voltage);                // send string data for printing
		LCD_Char('V');
		//Read The Second voltage
		LCD_Command(0xC0);		// Go to 1st line
		volt = (ADC_Read(2)*5);
		volt =volt/255.0;
		sprintf(voltage,"%d",volt);               // convert integer value to ASCII string
		LCD_String("volt(2)= ");
		LCD_String(voltage);                // send string data for printing
		LCD_Char('V');
		_delay_ms(100);
		
		
	
	
	}
	return 0;
}

void ADC_Init(){
	DDRA &=~(1<<0);
	DDRA &=~(1<<1);						        /* Make ADC port as input */
	ADCSRA =(1<<ADPS0) | (1<<ADPS1)	|(1<<ADPS2) | (1<<ADATE) | (1<<ADEN);							/* Enable ADC, with freq/128  */
	ADMUX =(1<<REFS0) | (1<<REFS1) |(1<<ADMUX0);		/* Vref: Internal , ADC channel: 1 */
}

unsigned int ADC_Read(char channel)
{
	ADMUX = 0xC0 | (channel & 0x07);				/* set input channel to read */
	ADCSRA |= (1<<ADSC);							/* Start ADC conversion */
	while (!(ADCSRA & (1<<ADIF)));					/* Wait until end of conversion by polling ADC interrupt flag */
	ADCSRA |= (1<<ADIF);							/* Clear interrupt flag */
	_delay_ms(1);									/* Wait a little bit */
	
	unsigned int dataADC=ADCL;
	dataADC|=(ADCH<<8);
	return dataADC;
	//return ADCW;									/* Return ADC word */
	
}
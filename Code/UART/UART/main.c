/*
 * UART.c
 *
 * Created: 11/29/2020 10:45:06 AM
 * Author : Abdelrahman_Magdy
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "Stepper.h"

#define Baud_Rate		9600
#define UBRR_Count ((F_CPU/(16UL*(Baud_Rate)))-1)      //103

void UART_Int();
void UART_Send( char data);
unsigned char  UART_Receive();
 void UART_Send_String( char *string);
 
int main(void)
{
   UART_Int();
   UART_Send_String("Abdo_Magdy\r\n");
   DDRC|=(1<<PC2);
   char Recive_data;
   DDRC|=(1<<Stepper_Leg_6)|(1<<Stepper_Leg_5)|(1<<Stepper_Leg_3)|(1<<Stepper_Leg_4);
   DDRD|=(1<<EN_1)|(1<<EN_2);
   PORTD|=(1<<EN_1)|(1<<EN_2);
    while (1) 
    {
		
	 
		Recive_data=UART_Receive();
		switch(Recive_data)
		{
			case '1' :
				 Stepper_Motor(1);
				 _delay_ms(2000);
				 PORTC=0x00;
			break;
			
			case '2' :
				Stepper_Motor(2);
				_delay_ms(2000);
				PORTC=0x00;
			break;
			
			case '3' :
				Stepper_Motor(3);
				_delay_ms(2000);
				PORTC=0x00;
			break;
			
			case '4' :
				Stepper_Motor(4);
				_delay_ms(2000);
				PORTC=0x00;
			break;									
		}
		
	
    }
}

void UART_Int()
{
	
	//ENable Transmit And Resiver 
	UCSRB|=(1<<RXEN)|(1<<TXEN);
	//Register Select  8_bit 
	UCSRC|=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1); 
	UBRRL=UBRR_Count;				//103 
}

void UART_Send( char data)
{
	 while (!(UCSRA&(1<<UDRE)));
	UDR=data;
}
void UART_Send_String( char *string)
{
      short i =0;
	 while(string[i]!='\0')
	 {
		    UART_Send(string[i]);
			i++;
	 }
}

unsigned char  UART_Receive()
{
	//make sure you have data 
	while(!(UCSRA&(1<<RXC)));
	return UDR;
}
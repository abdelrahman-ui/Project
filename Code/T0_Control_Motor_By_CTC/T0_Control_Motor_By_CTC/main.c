/*
 * T0_Control_Motor_By_CTC.c
 *
 * Created: 11/21/2020 9:02:37 AM
 * Author : Abdelrahman_Magdy
 */ 

#define F_CPU 16000000
#include <avr/io.h>
#include <avr/interrupt.h>


const unsigned char WaveTable[2]={76,178};
static unsigned char i=0;

int main(void)
{
	//SET DIR OF OC0
	DDRB|=(1<<PB3);
	//DIR OF MOTOR
	DDRD|=(1<<PD5)|(1<<PD6);
	PORTD|=(1<<PD5);
	// no prescaler &toggle &ctc
	TCCR0|=(1<<WGM01)|(1<<COM00)|(1<<CS00);
	//ENable ISR
	TIMSK|=(1<<OCIE0);
	//EN Global ISR
	sei();
	
    
    while (1) 
	{
		
	}
   
}


ISR(TIMER0_COMP_vect)
{
	
	OCR0=WaveTable[i];
	i++;
	if(i>=2)
		i=0;
	
}

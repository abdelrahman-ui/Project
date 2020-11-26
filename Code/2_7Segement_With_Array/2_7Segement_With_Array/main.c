/*
 * 2_7Segement_With_Array.c
 *
 * Created: 11/5/2020 10:39:35 PM
 * Author : User™
 */ 

#include <avr/io.h>
#include <util/delay.h>
//Stroage at the flash array of led(A,B,C,D,E,F,G)
unsigned char seg[]={0b0111111,0b0000110,0b1011011,0b1001111,0b1100110,0b1101101,0b1111101,0b1001111,0b1111111,0b1101111};
int main(void)
{
	int i=0;
    DDRA=0x7f;
	PORTA=seg[0];				//Initial by 0
	DDRB=0x7f;
	PORTA=seg[0];				//Initial by 0
	DDRC=0x00 ;
	PORTC=0x01;					//PULL UP Resistance
	SFIOR&=~(1<<PUD);           //PULL UP Resistance not be disable
    while (1) 
    {
		while((PINC&0x01)==0x01);        //do no thing
		i++;
		if(i==100)
		i=0;
		PORTA=seg[i%10];
		PORTB=seg[i/10];
		while((PINC&0x01)==0x00);		//when i still push do no thing
    }
}


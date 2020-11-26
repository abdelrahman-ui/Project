/*
 * Blinking_Led.c
 *
 * Created: 11/5/2020 2:10:55 PM
 * Author : User™
 */ 

#include <avr/io.h>
#include <util/delay.h>
unsigned char i;

void pattern_1_A();
void pattern_2_A();
void pattern_3_A();
void pattern_4_A();
void pattern_1_B();
void pattern_2_B();
void pattern_3_B();
void pattern_4_B();

int main(void)
{
    DDRA=0xff;
	PORTA=0x01;
    DDRB=0xff;
    PORTB=0x01;
    while (1) 
    {
	    pattern_1_A();
		pattern_1_B();
		pattern_2_A();
		pattern_2_B();
		pattern_3_A();
		pattern_3_B();
		pattern_4_A();
		pattern_4_B();
    }
}

void pattern_1_A()
{
	PORTA=0x01;
	for(i=0;i<8;i++)
	{
		_delay_ms(100);
		PORTA=(PORTA<<1);
	}
}
void pattern_2_A()
{
	PORTA=0x80;
	for(i=0;i<8;i++)
	{
		_delay_ms(100);
		PORTA=(PORTA>>1);
	}
}
void pattern_3_A()
{
	PORTA=0x01;
	for(i=0;i<8;i++)
	{
		_delay_ms(100);
		PORTA|=(PORTA<<1);
	}
}
void pattern_4_A()
{
	PORTA=0xff;
	for(i=0;i<8;i++)
	{
		_delay_ms(100);
		PORTA=(PORTA>>1);
	}
}
void pattern_1_B()
{
	PORTB=0x01;
	for(i=0;i<8;i++)
	{
		_delay_ms(100);
		PORTB=(PORTB<<1);
	}
}
void pattern_2_B()
{
	PORTB=0x80;
	for(i=0;i<8;i++)
	{
		_delay_ms(100);
		PORTB=(PORTB>>1);
	}
}
void pattern_3_B()
{
	PORTB=0x01;
	for(i=0;i<8;i++)
	{
		_delay_ms(100);
		PORTB|=(PORTB<<1);
	}
}
void pattern_4_B()
{
	PORTB=0xff;
	for(i=0;i<8;i++)
	{
		_delay_ms(100);
		PORTB=(PORTB>>1);
	}
}
/*
 * SPI_Slave.c
 *
 * Created: 11/30/2020 11:05:40 PM
 * Author : Abdelrahman_Magdy
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define SPI_MOSI      PB5
#define SPI_MISO	  PB6
#define SPI_SCK		  PB7
#define SPI_SS		  PB4
#define LED			  PC0




unsigned char SPI_S_TxRx(unsigned char data );
void SPI_Int();
int main(void)
{
	SPI_Int();
    DDRC|=(1<<LED);
    while (1) 
    {
		if(SPI_S_TxRx(0XFF)==0X01)
		{
			PORTC^=(1<<LED);
		}
		
    }
}

void SPI_Int()
{
	DDRB|=(1<<SPI_MISO);
	DDRB&=~(1<<SPI_MOSI)&(1<<SPI_SS);
	//EN SPI    & Prescaler Foc/4
	SPCR|=(1<<SPE);
	
}
unsigned char SPI_S_TxRx(unsigned char data )
{
	SPDR=data ;
	while(!(SPSR&(1<<SPIF)));
	return SPDR;
}
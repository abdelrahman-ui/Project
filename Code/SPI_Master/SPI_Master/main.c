/*
 * SPI_Master.c
 *
 * Created: 11/30/2020 10:29:39 PM
 * Author : Abdelrahman_Magdy
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define SPI_MOSI      PB5
#define SPI_MISO	  PB6
#define SPI_SCK		  PB7
#define SPI_SS_1	  PC0
#define LED				PC5

#define Slave_Dis(REG,BIT)	(REG|=(1<<BIT))
#define Slave_EN(REG,BIT)	(REG &=~(1<<BIT))


void SPI_Int();
unsigned char SPI_M_TxRx(unsigned char data );

int main(void)
{
	SPI_Int();
	Slave_EN(PORTC,SPI_SS_1);
	DDRC|=(1<<LED);
    while (1) 
    {
		
		if (SPI_M_TxRx(0X01)==0XFF)
		{
			PORTC^=(1<<LED);
		}
		_delay_ms(1000);
	
    }
}


void SPI_Int()
{
	    DDRB|=(1<<SPI_MOSI)|(1<<SPI_SCK);
	    DDRB&=~(1<<SPI_MISO);
	    DDRC|=(1<<SPI_SS_1);
	    //EN SPI  & EN_Master  & Prescaler Foc/4
	    SPCR|=(1<<MSTR)|(1<<SPE);
	
}
unsigned char SPI_M_TxRx(unsigned char data )
{
	SPDR=data ;
	while(!(SPSR&(1<<SPIF)));
	return SPDR;
}
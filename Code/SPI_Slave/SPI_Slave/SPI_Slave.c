/*
 * SPI_Slave.c
 *
 * Created: 12/2/2020 2:00:01 PM
 *  Author: Abdelrahman_Magdy
 */ 

#include "SPI_Slave.h"

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
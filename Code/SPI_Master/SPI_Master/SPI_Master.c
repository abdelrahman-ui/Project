/*
 * SPI_Master.c
 *
 * Created: 12/2/2020 1:55:44 PM
 *  Author: Abdelrahman_Magdy
 */ 

#include "SPI_Master.h"
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
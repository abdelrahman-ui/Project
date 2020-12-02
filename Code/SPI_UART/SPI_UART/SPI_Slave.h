/*
 * SPI_Slave.h
 *
 * Created: 12/2/2020 1:59:09 PM
 *  Author: Abdelrahman_Magdy
 */ 


#ifndef SPI_SLAVE_H_
#define SPI_SLAVE_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define SPI_MOSI      PB5
#define SPI_MISO	  PB6
#define SPI_SCK		  PB7
#define SPI_SS		  PB4





unsigned char SPI_S_TxRx(unsigned char data );
void SPI_S_Int();



#endif /* SPI_SLAVE_H_ */
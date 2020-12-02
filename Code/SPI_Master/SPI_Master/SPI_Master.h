/*
 * SPI_Master.h
 *
 * Created: 12/2/2020 1:55:08 PM
 *  Author: Abdelrahman_Magdy
 */ 


#ifndef SPI_MASTER_H_
#define SPI_MASTER_H_

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


#endif /* SPI_MASTER_H_ */
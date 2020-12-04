/*
 * I2C_Slave.c
 *
 * Created: 12/4/2020 4:49:41 AM
 *  Author: Abdelrahman_Magdy
 */ 

#include "I2C_Slave.h"

void TWI_S_Init(void) // Function to initilaize slave
{
	TWAR=0x01;	// Fill slave address to TWAR
}

void TWI_write_slave(void) // Function to write data
{
	TWDR= write_data;	          // Fill TWDR register whith the data to be sent
	TWCR= (1<<TWEN)|(1<<TWINT);   // Enable TWI, Clear TWI interrupt flag
	while((TWSR & 0xF8) != 0xC0); // Wait for the acknowledgement
}

void TWI_match_write_slave(void) //Function to match the slave address and slave dirction bit(write)
{
	while((TWSR & 0xF8)!= 0xA8)	// Loop till correct acknoledgement have been received
	{
		// Get acknowlegement, Enable TWI, Clear TWI interrupt flag
		TWCR=(1<<TWEA)|(1<<TWEN)|(1<<TWINT);
		while (!(TWCR & (1<<TWINT)));  // Wait for TWINT flag
	}
}

unsigned char TWI_read_slave(void)
{
	// Clear TWI interrupt flag,Get acknowlegement, Enable TWI
	TWCR= (1<<TWINT)|(1<<TWEA)|(1<<TWEN);
	while (!(TWCR & (1<<TWINT)));	// Wait for TWINT flag
	while((TWSR & 0xF8)!=0x80);		// Wait for acknowledgement
	recv_data=TWDR;					// Get value from TWDR
	return recv_data;				// send the receive value on PORTB
}

void TWI_match_read_slave(void) //Function to match the slave address and slave dirction bit(read)
{
	while((TWSR & 0xF8)!= 0x60)  // Loop till correct acknoledgement have been received
	{
		// Get acknowlegement, Enable TWI, Clear TWI interrupt flag
		TWCR=(1<<TWEA)|(1<<TWEN)|(1<<TWINT);
		while (!(TWCR & (1<<TWINT)));  // Wait for TWINT flag
	}
}
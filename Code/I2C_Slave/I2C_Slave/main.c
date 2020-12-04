/*
 * I2C_Slave.c
 *
 * Created: 12/3/2020 10:59:40 PM
 * Author : Abdelrahman_Magdy
 */ 

#include "I2C_Slave.h"

int main(void)
{
	TWI_S_Init();
	DDRC|=(1<<PC4);
	while(1)
	{
		TWI_match_read_slave();	//Function to match the slave address and slave dirction bit(read)
		if(TWI_read_slave()=='m')	// Function to read data
			PORTC|=(1<<PC4);
		/*write_data=~recv_data;	// Togglem the receive data
		
		TWI_match_write_slave(); //Function to match the slave address and slave dirction bit(write)
		TWI_write_slave();       // Function to write data*/
	}
		
}

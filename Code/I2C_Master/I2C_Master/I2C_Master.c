/*
 * I2C_Master.c
 *
 * Created: 12/4/2020 4:32:18 AM
 *  Author: Abdelrahman_Magdy
 */ 
#include "I2C_Master.h"

void I2C_M_Init(void)
{
	/*//Scl=4khz
	TWBR=0x03;
	TWSR|=(0<<TWPS1)|(1<<TWPS0*/
		TWBR=0x01;	// Bit rate
		TWSR=(0<<TWPS1)|(0<<TWPS0);	// Setting prescalar bits
		// SCL freq= F_CPU/(16+2(TWBR).4^TWPS)
}

void I2C_M_Start(void)
{
	TWCR|=(1<<TWINT)|(1<<TWSTA)|(TWEN);				//Clear TWI FLAG BY LOGIC 1 & EN I2C & START
	while(! (TWCR & (1<<TWINT)));					//Wait Untill TWINT SET
	while((TWSR & 0xf8) !=Start_ACK);				//Check ACK
	
}

void I2C_M_Stop(void)
{
	TWCR|=(1<<TWINT)|(1<<TWSTO)|(TWEN);				//Clear TWI FLAG BY LOGIC 1 & EN I2C & STop
	while(!(TWCR & (1<<TWSTO)));  // Wait till stop condition is transmitted

}

void I2C_M_Write_Address(unsigned char Address)
{
	TWDR=Address;
	TWCR|=(1<<TWINT)|(TWEN);				//Clear TWI FLAG BY LOGIC 1 & EN I2C
	while(! (TWCR & (1<<TWINT)));					//Wait Untill TWINT SET
	while((TWSR & 0xf8) !=Address_W_ACK);				//Check ACK
}

void I2C_M_Read_Address(unsigned char Address)
{
	TWDR=Address;
	TWCR|=(1<<TWINT)|(TWEN);				//Clear TWI FLAG BY LOGIC 1 & EN I2C
	while(! (TWCR & (1<<TWINT)));					//Wait Untill TWINT SET
	while((TWSR & 0xf8) !=Address_R_ACK);				//Check ACK
}
void I2C_M_Write_Data(unsigned char data)
{
	TWDR=data;
	TWCR|=(1<<TWINT)|(TWEN);				//Clear TWI FLAG BY LOGIC 1 & EN I2C
	while(! (TWCR & (1<<TWINT)));					//Wait Untill TWINT SET
	while((TWSR & 0xf8) !=Data_W_ACK);				//Check ACK
}
unsigned char I2C_Read_Data(void)
{
	TWCR|=(1<<TWINT)|(TWEN);				//Clear TWI FLAG BY LOGIC 1 & EN I2C
	while(! (TWCR & (1<<TWINT)));					//Wait Untill TWINT SET
	while((TWSR & 0xf8) !=Data_R_ACK);				//Check ACK
	return recv_data ;
}
void I2C_Repeatead_Start()
{
	// Clear TWI interrupt flag, Put start condition on SDA, Enable TWI
	TWCR= (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while(!(TWCR & (1<<TWINT))); // wait till restart condition is transmitted
	while((TWSR & 0xF8)!= Repeat_ACK); // Check for the acknoledgement
}
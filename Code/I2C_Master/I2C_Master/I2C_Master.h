/*
 * I2C_Master.h
 *
 * Created: 12/4/2020 4:31:25 AM
 *  Author: Abdelrahman_Magdy
 */ 


#ifndef I2C_MASTER_H_
#define I2C_MASTER_H_
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <math.h>


#define Start_ACK  0X08
#define Address_W_ACK 0X18
#define Address_R_ACK 0X40
#define Data_W_ACK 0x28
#define Data_R_ACK 0x58
#define Repeat_ACK	0x10
unsigned char recv_data;

void I2C_M_Init(void);
void I2C_M_Start(void);
void I2C_M_Stop(void);
void I2C_M_Write_Address(unsigned char Address);
void I2C_M_Read_Address(unsigned char Address);
void I2C_M_Write_Data(unsigned char data);
unsigned char I2C_Read_Data(void);
void I2C_Repeatead_Start();




#endif /* I2C_MASTER_H_ */
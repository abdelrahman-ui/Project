/*
 * I2C_Slave.h
 *
 * Created: 12/4/2020 4:48:54 AM
 *  Author: Abdelrahman_Magdy
 */ 


#ifndef I2C_SLAVE_H_
#define I2C_SLAVE_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <math.h>

void TWI_init_slave(void);
void TWI_match_read_slave(void);
unsigned char TWI_read_slave(void);
void TWI_match_write_slave(void);
void TWI_write_slave(void);

unsigned write_data,recv_data;



#endif /* I2C_SLAVE_H_ */
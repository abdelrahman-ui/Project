/****************************************************************
 ************   -Dio_reg.h                 *******************
 ***********					   		       ******************
 ***********   -Created: 1/30/2021 1:06:25 AM  ******************
 ***********   -Author: Abdelrahman_Magdy      ******************
 ***********   -Version : _1_				   ******************
 ***********  - Using Pre_build Configeration  ******************
 ****************************************************************/ 

/****************************************************************
***********  guard of file will call on time in .c  *************
******************************************************************/
#ifndef _DIO_REG_H
#define _DIO_REG_H

/* Group A Regs */
#define PORTA_Reg  (*(volatile uint8_t*)0x3B)
#define DDRA_Reg   (*(volatile uint8_t*)0x3A)
#define PINA_Reg   (*(volatile uint8_t*)0x39)

/* Group B Regs */
#define PORTB_Reg  (*(volatile uint8_t*)0x38)
#define DDRB_Reg   (*(volatile uint8_t*)0x37)
#define PINB_Reg   (*(volatile uint8_t*)0x36)

/* Group C Regs */
#define PORTC_Reg  (*(volatile uint8_t*)0x35)
#define DDRC_Reg   (*(volatile uint8_t*)0x34)
#define PINC_Reg   (*(volatile uint8_t*)0x33)

/* Group D Regs */
#define PORTD_Reg  (*(volatile uint8_t*)0x32)
#define DDRD_Reg   (*(volatile uint8_t*)0x31)
#define PIND_Reg   (*(volatile uint8_t*)0x30)


#endif

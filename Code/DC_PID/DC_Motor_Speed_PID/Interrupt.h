﻿
/****************************************************************
 ************   -Interrupt.h                 *******************
 ***********					   		       ******************
 ***********   -Created: 1/30/2021 1:06:25 AM  ******************
 ***********   -Author: Abdelrahman_Magdy      ******************
 ***********   -Version : _1_				   ******************
 ***********  - Using Pre_build Configeration  ******************
 ****************************************************************/ 

/****************************************************************
***********  guard of file will call on time in .c  *************
******************************************************************/

#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#define Low_Lvl 0
#define Logical_Change 1
#define Falling_Edge 2
#define Rising_Edge 3


void INT0_Init(uint8_t Int_Mode);
void INT1_Init(uint8_t Int_Mode);
void INT2_Init(uint8_t Int_Mode);


#endif /* INTERRUPT_H_ */
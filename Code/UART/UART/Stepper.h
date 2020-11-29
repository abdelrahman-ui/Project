/*
 * Stepper.h
 *
 * Created: 11/30/2020 12:43:59 AM
 *  Author: Abdelrahman_Magdy
 */ 


#ifndef STEPPER_H_
#define STEPPER_H_


#define Stepper_Leg_3	PC3
#define Stepper_Leg_4	PC4
#define Stepper_Leg_5	PC5
#define Stepper_Leg_6	PC6

#define EN_1		PD4
#define EN_2		PD5

void Stepper_Motor(unsigned char Mode);

#endif /* STEPPER_H_ */
/*
 * Servo_Motor.c
 *
 * Created: 11/23/2020 8:35:57 AM
 * Author : Abdelrahman_Magdy
 */ 
 
#define  F_CPU 16000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define Mini_Count		250
#define Max_Count		500
#define Mini_Angle       0
#define Max_Angle       180

void Servo_Motor(unsigned short angle );

int main(void)
{	
	DDRD|=(1<<PD4)|(1<<PD5);  //OC1B &OC1A OUTPUT
		//Mode 14
    TCCR1A|=(1<<WGM11);
	TCCR1B|=(1<<WGM12)|(1<<WGM13);   
	//PreScaler
	TCCR1B|=(1<<CS10)|(1<<CS11);
	//Comper Output Mode
	TCCR1A|=(1<<COM1A1);
	//PUT Your Frequancy  F=5000
	ICR1=4999;
	
    while (1) 
    {
		Servo_Motor(0);
		_delay_ms(2000);
		Servo_Motor(45);
		_delay_ms(2000);
		Servo_Motor(90);
		_delay_ms(2000);
		Servo_Motor(125);
		_delay_ms(2000);
		Servo_Motor(180);
		_delay_ms(2000);
    }
}
//Duty Cycle
void Servo_Motor(unsigned short angle )
{
	OCR1A=((angle-Mini_Angle)*(Max_Count-Mini_Count)/(Max_Angle-Mini_Angle))+Mini_Count-1;
}
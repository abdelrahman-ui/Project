/*
 * I2C_Master.c
 *
 * Created: 12/3/2020 8:52:36 PM
 * Author : Abdelrahman_Magdy
 */ 

 #include "I2C_Master.h"
 
int main(void)
{
	I2C_M_Init();
   
    while (1) 
    {
		I2C_M_Start();
		I2C_M_Write_Address(0X01);
		I2C_M_Write_Data('m');
		I2C_M_Stop();
    }
}

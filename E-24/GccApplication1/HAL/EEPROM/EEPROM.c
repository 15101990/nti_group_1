/*
 * EEPROM.c
 *
 * Created: 21/01/2022 03:28:27 م
 *  Author: dell
 */ 
#include "STD.h"
#include "I2C.h"
#include "LED.h"

void EEPROM_INIT(void)
{
	I2C_INIT();
}
void EEPROM_WRITE(u8 data,u8 page,u8 byte)
{
	if((page < 8) && (byte < 256))
	{
		I2C_START_CONDITION();
		I2C_SEND_SLAVE_ADDRESS_WRITE(0x50 | page);
		I2C_SEND_BYTE(byte);
		I2C_SEND_BYTE(data);
		I2C_STOP_CONDITION();
	}      
}
u8   EEPROM_READ(u8 page,u8 byte)
{
	u8 data = 0;
	if((page < 8) && (byte < 256))
	{
		I2C_START_CONDITION();
		I2C_SEND_SLAVE_ADDRESS_WRITE(0x50 | page);
		I2C_SEND_BYTE(byte);
		I2C_REPEATED_START();
		I2C_SEND_SLAVE_ADDRESS_READ(0x50 | page);
		data = I2C_REC_BYTE();
		I2C_STOP_CONDITION();
	}	
	return data;
}
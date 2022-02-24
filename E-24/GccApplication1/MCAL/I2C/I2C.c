/*
 * I2C.c
 *
 * Created: 15/01/2022 02:52:16 م
 *  Author: dell
 */ 
#include "I2C_CFG.h"
#include "I2C.h"
#include "STD.h"
//#include "DIO.h"
#include "LED.h"
#include "BIT_MATH.h"
#include "REG.h"

void I2C_INIT(void)
{
	#if   I2C_MODE   ==   MASTER
	/* to select 400 k hz I2C frequancy*/
	TWBR = 12;
	#elif I2C_MODE   ==   SLAVE
	/*to select slave address = 0000001 and enable rec byte from broadcast*/
	TWAR = 0b00000011;
	#endif
	/*to enable I2C circuit*/
	SET_BIT(TWCR,2);
}
void I2C_START_CONDITION(void)
{
	SET_BIT(TWCR,5);
	SET_BIT(TWCR,7);    // to enable clearing this bit
	while(GET_BIT(TWCR,7) == 0);
	while((TWSR & 0xF8) != START_ACK);
}
void I2C_SEND_SLAVE_ADDRESS_WRITE(u8 address) 
{
	TWDR = (address << 1);
	SET_BIT(TWCR,7);    // to enable clearing this bit
	while(GET_BIT(TWCR,7) == 0);
	while((TWSR & 0xF8) != SLAVE_AD_AND_WR_ACK);
}
void I2C_SEND_SLAVE_ADDRESS_READ(u8 address)
{
	TWDR = ((address << 1) | (0x01));
	SET_BIT(TWCR,7);                 // to clear flag
	while(GET_BIT(TWCR,7) == 0);
	while((TWSR & 0xF8) != SLAVE_AD_AND_RD_ACK);
}
void I2C_SEND_BYTE(u8 byte)
{
	TWDR = byte;
	CLR_BIT(TWCR,5);
	SET_BIT(TWCR,7);    // to enable clearing this bit
	while(GET_BIT(TWCR,7) == 0);
	while((TWSR & 0xF8) != WR_BYTE_ACK);
}
u8   I2C_REC_BYTE(void)
{
	u8 data = 0;
	CLR_BIT(TWCR,5);
	CLR_BIT(TWCR,4);
	SET_BIT(TWCR,6);
	SET_BIT(TWCR,7);                 // to clear flag
	while(GET_BIT(TWCR,7) == 0);
	while((TWSR & 0xF8) != RD_BYTE_WITH_ACK);
	data = TWDR;
	return data;
}
void I2C_REPEATED_START(void)
{
	SET_BIT(TWCR,5);                 // to make start condition
	SET_BIT(TWCR,7);                 // to clear flag
	while(GET_BIT(TWCR,7) == 0);
	while((TWSR&0xF8) != REP_START_ACK);
}
void I2C_STOP_CONDITION(void)
{
	SET_BIT(TWCR,4);
	SET_BIT(TWCR,7);

}
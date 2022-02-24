/*
 * SPI.c
 *
 * Created: 14/01/2022 02:53:09 م
 *  Author: dell
 */ 

#include "SPI_CFG.h"
#include "SPI.h"
#include "STD.h"
#include "DIO.h"
#include "BIT_MATH.h"
#include "REG.h"

void SPI_INIT(void)
{
	#if   SPI_MODE     ==   MASTER
	PIN_MODE(MOSI,OUTPUT);
	PIN_MODE(MISO,INPUT);
	PIN_MODE(SCK,OUTPUT);
	PIN_MODE(SS,OUTPUT);
	//to select master mode
	SET_BIT(SPCR,4);
	//to write bit with leading edge
	SET_BIT(SPCR,2);
	//to select 128 devision factor
	SET_BIT(SPCR,0);
	SET_BIT(SPCR,1);
	#elif SPI_MODE     ==   SLAVE
	PIN_MODE(MOSI,INPUT);
	PIN_MODE(MISO,OUTPUT);
	PIN_MODE(SCK,INPUT);
	PIN_MODE(SS,INPUT);
	//to select slave mode	
	CLR_BIT(SPCR,4);
	//to read bit with leading edge
	CLR_BIT(SPCR,2);
	#endif
	// to enable global interrupt
	//SET_BIT(SREG,7);
	//to enable spi interrupt
	//SET_BIT(SPCR,7);
	// to enable SPI driver
	SET_BIT(SPCR,6);
}
u8   SPI_TRANSIVE(u8 data)
{
	SPDR = data;
	while(GET_BIT(SPSR,7) == 0);
	return SPDR;
}
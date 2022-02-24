/*
 * UART.c
 *
 * Created: 01/01/2022 04:15:37 م
 *  Author: dell
 */ 

#include "BIT_MATH.h"
#include "DIO.h"
#include "REG.h"

void UART_INIT(void)
{
	PIN_MODE(PD0,INPUT);
	PIN_MODE(PD1,OUTPUT);
	UBRRL = 103; // to get 9600 buad rate
	/*to select 8bits*/
	UCSRC = 0b10100110;
	CLR_BIT(UCSRB,2);
	/*to enable rec and tr*/
	SET_BIT(UCSRB,3);
	SET_BIT(UCSRB,4);
}
void UART_SEND(u8 data)
{
	UDR = data;
	while(GET_BIT(UCSRA,6) == 0);
}
u8   UART_REC(void)
{
	while(GET_BIT(UCSRA,7) == 0);
	return UDR;
}
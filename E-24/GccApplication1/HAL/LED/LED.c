/*
 * LED.c
 *
 * Created: 04/12/2021 05:29:02 م
 *  Author: dell
 */ 
#include "LED_CFG.h"
#include "DIO.h"

void LED_INIT(u8 x)
{
	switch (x)
	{
		case 0:
		PIN_MODE(LED_0_PIN,OUTPUT);
		break;
		case 1:
		PIN_MODE(LED_1_PIN,OUTPUT);
		break;
		case 2:
		PIN_MODE(LED_2_PIN,OUTPUT);
		break;
		default:
		break;
	}
}
void LED_ON(u8 x)
{
	PIN_WRITE(PC2,HIGH);
}
void LED_OFF(void)
{
	PIN_WRITE(PC2,LOW);
}
void LED_TOG(u8 x)
{
	PIN_TOGGLE(PC2);
}
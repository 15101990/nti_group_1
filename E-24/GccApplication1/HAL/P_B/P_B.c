/*
 * P_B.c
 *
 * Created: 10/12/2021 02:10:02 م
 *  Author: dell
 */ 
#include "P_B_CFG.h"
#include "DIO.h"

void P_B_INIT(u8 x)
{
	switch(x)
	{
		case 0:
		PIN_MODE(P_B_0_PIN,INPUT);
		break;
		case 1:	
		PIN_MODE(P_B_1_PIN,INPUT);
		break;
		case 2:
		PIN_MODE(P_B_2_PIN,INPUT);
		break;
		default:
		break;
	}
}
u8   P_B_READ(u8 x)
{
	u8 reading = 0;
	switch(x)
	{
		case 0:
		reading = PIN_READ(P_B_0_PIN);
		break;
		case 1:
		reading = PIN_READ(P_B_1_PIN);
		break;
		case 2:
		reading = PIN_READ(P_B_2_PIN);
		break;
		default:
		break;
	}	
	return reading;
}
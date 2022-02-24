/*
 * EXT_INT.c
 *
 * Created: 18/12/2021 02:09:32 م
 *  Author: dell
 */ 

#include "BIT_MATH.h"
#include "REG.h"

void EXT_INT_INIT(void)
{
	SET_BIT(SREG,7);     // to enable global interrupt
	SET_BIT(GICR,6);     // to enable interrupt for int0
	SET_BIT(MCUCR,0);    //  to select rising edge to fire interrupt
	SET_BIT(MCUCR,1);
}

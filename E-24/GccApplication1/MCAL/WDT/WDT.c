/*
 * WDT.c
 *
 * Created: 01/01/2022 02:24:52 م
 *  Author: dell
 */ 

#include "BIT_MATH.h"
#include "REG.h"

void WDT_INIT(void)
{
	/* to enable watch dog timer*/
	SET_BIT(WDTCR,3);
	/*to select 2.1 second*/
	SET_BIT(WDTCR,0);
	SET_BIT(WDTCR,1);
	SET_BIT(WDTCR,2);
}
void WDT_REFRESH(void)
{
	asm("WDR");
}
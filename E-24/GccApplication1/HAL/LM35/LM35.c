/*
 * LM35.c
 *
 * Created: 24/12/2021 04:15:45 م
 *  Author: dell
 */ 
#include "ADC.h"
#include "STD.h"

void LM35_INIT(void)
{
	ADC_INIT();
}
u16  LM35_READ(void)
{
	u32 adc_reading = ADC_READ();
	u32 temp = ((adc_reading * 500 ) / 1023);
	return temp;
}
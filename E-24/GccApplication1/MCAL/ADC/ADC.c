/*
 * ADC.c
 *
 * Created: 24/12/2021 02:07:08 م
 *  Author: dell
 */ 
#include "BIT_MATH.h"
#include "REG.h"
#include "STD.h"

void ADC_INIT(void)
{
	/* to select AVCC */
	SET_BIT(ADMUX,6);
	CLR_BIT(ADMUX,7);
	/*to select right adjust*/
	CLR_BIT(ADMUX,5);
	/* to select ADC1*/
	SET_BIT(ADMUX,0);
	CLR_BIT(ADMUX,1);
	CLR_BIT(ADMUX,2);
	CLR_BIT(ADMUX,3);
	CLR_BIT(ADMUX,4);
	/*to select auto trigger mode*/
	SET_BIT(ADCSRA,5);
	/*to select 128 division factor*/
	SET_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);
	/* to enable ADC*/
	SET_BIT(ADCSRA,7);
}
u16  ADC_READ(void)
{
	/*to start conversion*/
	SET_BIT(ADCSRA,6);
	while(GET_BIT(ADCSRA,4) == 0);
	return ADCL;
}
/*
 * TIMERS.c
 *
 * Created: 25/12/2021 02:18:56 م
 *  Author: dell
 */ 
#include "TIMERS_CFG.h"
#include "TIMERS.h"
#include "STD.h"
#include "BIT_MATH.h"
#include "REG.h"

u32 no_of_ov;
u8  rem_ticks;
u32 no_of_cm;
void TIMER_0_INIT(void)
{
	SET_BIT(SREG,7);
	#if TIMER_0_MODE   ==  NORMAL_MODE
	CLR_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);
	/*to enable timer0 ov int*/
	SET_BIT(TIMSK,0);
	#elif TIMER_0_MODE == CTC_MODE
	SET_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);
	/*to enable timer0 cm int*/
	SET_BIT(TIMSK,1);
	#endif
}
void TIMER_0_SET_TIME(u32 desire_time)
{
	#if TIMER_0_MODE   == NORMAL_MODE
	u32 tick_time   = TIMER_0_PRESCALER / CRYSTAL_FREQUANCY;     //  result will be in micro second
	u32 total_ticks = (desire_time * 1000) / tick_time;
	no_of_ov        = total_ticks / 256;
	rem_ticks       = total_ticks % 256;
	if(rem_ticks != 0)
	{
		TCNT0 = 256 - rem_ticks;
		no_of_ov++;	
	}
	#elif TIMER_0_MODE   ==  CTC_MODE
	u32 x = 0;
	u32 tick_time   = TIMER_0_PRESCALER / CRYSTAL_FREQUANCY;     //  result will be in micro second
	u32 total_ticks = (desire_time * 1000) / tick_time;
	for(x = 255 ;x>0;x--)
	{
		if ((total_ticks % x) == 0)
		break;
	}
	no_of_cm        = total_ticks / x;
	OCR0 = x - 1;
	#endif
}
void TIMER_0_START(void)
{
	#if   TIMER_0_PRESCALER  == 1024
	SET_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	SET_BIT(TCCR0,2);
	#elif TIMER_0_PRESCALER  == 256
	CLR_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	SET_BIT(TCCR0,2);
	#endif
	
}
void TIMER_0_STOP(void)
{
	CLR_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);
}

void PWM_0_INIT(void)
{
	SET_BIT(TCCR0,3);
	SET_BIT(TCCR0,6);
	SET_BIT(DDRB,3);
	#if   FAST_PWM_MODE  ==  NON_INVERTED
	CLR_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
	#elif FAST_PWM_MODE  ==  INVERTED
	SET_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
	#endif
}
void PWM_0_SET_DUTY_CYCLE(u8 duty_cycle)
{
	#if   FAST_PWM_MODE  ==    NON_INVERTED
	OCR0 = ((duty_cycle * 256 ) / 100 ) - 1;
	#elif FAST_PWM_MODE  ==  INVERTED
	OCR0 = (((duty_cycle * 256 ) / 100 ) - 255) * -1;
	#endif
}
void PWM_0_START(void)
{
	TIMER_0_START();
}
void PWM_0_STOP(void)
{
	TIMER_0_STOP();
}

void PWM_1_INIT(void)
{
	SET_BIT(DDRD,5); 
	/* to select fast pwm mode with ICR1 as top*/
	CLR_BIT(TCCR1A,0);
	SET_BIT(TCCR1A,1);
	SET_BIT(TCCR1B,3);
	SET_BIT(TCCR1B,4);
	/* to select non inverted mode*/
	CLR_BIT(TCCR1A,6);
	SET_BIT(TCCR1A,7);
	/* to select 50 Hz*/
	ICR1 = 1250;
}
void PWM_1_SET_DUTY_CYCLE(u8 duty_cycle)
{
	OCR1A = ((duty_cycle * 1250 ) / 100 ) - 1;
}
void PWM_1_START(void)
{
	CLR_BIT(TCCR1B,0);
	CLR_BIT(TCCR1B,1);
	SET_BIT(TCCR1B,2);
}
void PWM_1_STOP(void)
{
	CLR_BIT(TCCR1B,0);
	CLR_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,2);	
}
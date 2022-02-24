/*
 * TIMERS.h
 *
 * Created: 25/12/2021 02:19:11 م
 *  Author: dell
 */ 


#ifndef TIMERS_H_
#define TIMERS_H_

#include "STD.h"

void TIMER_0_INIT(void);
void TIMER_0_SET_TIME(u32);
void TIMER_0_START(void);
void TIMER_0_STOP(void);

void PWM_0_INIT(void);
void PWM_0_SET_DUTY_CYCLE(u8);
void PWM_0_START(void);
void PWM_0_STOP(void);

void PWM_1_INIT(void);
void PWM_1_SET_DUTY_CYCLE(u8);
void PWM_1_START(void);
void PWM_1_STOP(void);

#define NORMAL_MODE     1
#define CTC_MODE        2

#define NON_INVERTED     0
#define INVERTED         1

#endif /* TIMERS_H_ */
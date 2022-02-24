/*
 * SERVO.c
 *
 * Created: 23/02/2022 10:55:19 ص
 *  Author: dell
 */ 
#include "SERVO_CFG.h"
#include "TIMER_1.h"
#include "STD_TYPES.h"

void SERVO_INIT(void)
{
	PWM_1_INIT();
	PWM_1_SET_FREQUANCY(SERVO_FREQUANCY);
}
void SERVO_SET_ANGLE(u8 angle)
{
	PWM_1_SET_DUTY_CYCLE((((u32)angle * 5) / 180 ) + 5);
}
void SERVO_START(void)
{
	PWM_1_START();
}
void SERVO_STOP(void)
{
	PWM_1_STOP();
}
/*
 * DC_MOTOR.c
 *
 * Created: 31/12/2021 03:42:09 م
 *  Author: dell
 */ 
#include "DC_MOTOR_CFG.h"
#include "DC_MOTOR.h"
#include "DIO.h"
#include "TIMERS.h"

void DC_MOTOR_INIT(void)
{
	PWM_0_INIT();
	PIN_MODE(DC_MOTOR_DIRECTION_PIN_1,OUTPUT);
	PIN_MODE(DC_MOTOR_DIRECTION_PIN_2,OUTPUT);
}
void DC_MOTOR_START(void)
{
	PWM_0_START();
}
void DC_MOTOR_STOP(void)
{
	PWM_0_STOP();
}
void DC_MOTOR_SET_SPEED_DIRECTION(u8 speed,u8 direction)
{
	switch(direction)
	{
		case CLK_WISE:
		PIN_WRITE(DC_MOTOR_DIRECTION_PIN_1,HIGH);
		PIN_WRITE(DC_MOTOR_DIRECTION_PIN_2,LOW);
		break;
		case ANTI_CLK_WISE:
		PIN_WRITE(DC_MOTOR_DIRECTION_PIN_1,LOW);
		PIN_WRITE(DC_MOTOR_DIRECTION_PIN_2,HIGH);
		break;
		default:
		break;
	}
	PWM_0_SET_DUTY_CYCLE(speed);
}
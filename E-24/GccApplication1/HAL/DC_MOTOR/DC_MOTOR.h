/*
 * DC_MOTOR.h
 *
 * Created: 31/12/2021 03:42:20 م
 *  Author: dell
 */ 


#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "STD.h"

void DC_MOTOR_INIT(void);
void DC_MOTOR_START(void);
void DC_MOTOR_STOP(void);
void DC_MOTOR_SET_SPEED_DIRECTION(u8,u8);

#define CLK_WISE        0
#define ANTI_CLK_WISE   1

#endif /* DC_MOTOR_H_ */
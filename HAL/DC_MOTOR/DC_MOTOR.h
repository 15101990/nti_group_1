/*
 * DC_MOTOR.h
 *
 * Created: 22/02/2022 01:27:56 م
 *  Author: dell
 */ 


#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "STD_TYPES.h"

void DC_MOTOR_INIT(void);
void DC_MOTOR_SET_DIR(u8);
void DC_MOTOR_SET_SPEED(u8);
void DC_MOTOR_START(void);
void DC_MOTOR_STOP(void);

#define CLK        0
#define ACLK       1

#endif /* DC_MOTOR_H_ */
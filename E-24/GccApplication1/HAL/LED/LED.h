/*
 * LED.h
 *
 * Created: 04/12/2021 05:29:14 م
 *  Author: dell
 */ 


#ifndef LED_H_
#define LED_H_

#include "STD.h"

void LED_INIT(u8);
void LED_ON(u8);
void LED_TOG(u8);
void LED_OFF(void);

#define LED_0    0
#define LED_1    1
#define LED_2    2

#endif /* LED_H_ */
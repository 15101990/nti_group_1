/*
 * UART.h
 *
 * Created: 01/01/2022 04:15:48 م
 *  Author: dell
 */ 


#ifndef UART_H_
#define UART_H_

#include "BIT_MATH.h"

void UART_INIT(void);
void UART_SEND(u8);
u8   UART_REC(void);

#endif /* UART_H_ */
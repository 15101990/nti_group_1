/*
 * SPI.h
 *
 * Created: 14/01/2022 02:53:20 م
 *  Author: dell
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "STD.h"

void SPI_INIT(void);
u8   SPI_TRANSIVE(u8);

#define MASTER    1
#define SLAVE     2

#endif /* SPI_H_ */
/*
 * DIO.h
 *
 * Created: 04/12/2021 02:03:10 م
 *  Author: dell
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "STD.h"

void PIN_MODE(u8,u8);
void PIN_WRITE(u8,u8);
u8   PIN_READ(u8);
void PIN_TOGGLE(u8);
void PORT_MODE(u8,u8);
void PORT_WRITE(u8,u8);
u8   PORT_READ(u8);
void PIN_PULL_UP_RES(u8,u8);

/**************************SPI_PINS****************************/
#define MOSI            PB5
#define MISO            PB6
#define SCK             PB7
#define SS              PB4

#define PA0     0
#define PA1     1
#define PA2     2
#define PA3     3
#define PA4     4
#define PA5     5
#define PA6     6
#define PA7     7

#define PB0     10
#define PB1     11
#define PB2     12
#define PB3     13
#define PB4     14
#define PB5     15
#define PB6     16
#define PB7     17

#define PC0     20
#define PC1     21
#define PC2     22
#define PC3     23
#define PC4     24
#define PC5     25
#define PC6     26
#define PC7     27

#define PD0     30
#define PD1     31
#define PD2     32
#define PD3     33
#define PD4     34
#define PD5     35
#define PD6     36
#define PD7     37

#define OUTPUT     1
#define INPUT      0

#define LOW        0
#define HIGH       1

#define DISABLE    0
#define ENABLE     1


#define A    0
#define B    1
#define C    2
#define D    3
#endif /* DIO_H_ */
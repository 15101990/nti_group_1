/*
 * EEPROM.h
 *
 * Created: 21/01/2022 03:28:38 م
 *  Author: dell
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include "STD.h"

void EEPROM_INIT(void);
void EEPROM_WRITE(u8,u8,u8);
u8   EEPROM_READ(u8,u8);

#endif /* EEPROM_H_ */
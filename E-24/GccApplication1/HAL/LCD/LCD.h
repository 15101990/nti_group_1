/*
 * LCD.h
 *
 * Created: 11/12/2021 02:04:05 م
 *  Author: dell
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "STD.h"
void LCD_INIT(void);
void LCD_SEND_CHR(u8);
void LCD_SEND_CMD(u8);
void LCD_SEND_STR(u8*);
void LCD_WRITE_INT (u32);
void LCD_CLR(void);
#define _4_BIT_MODE      4
#define _8_BIT_MODE      8

#endif /* LCD_H_ */
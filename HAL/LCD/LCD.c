/*
 * LCD.c
 *
 * Created: 13/02/2022 10:09:28 ص
 *  Author: dell
 */ 

#include "LCD_CFG.h"
#include "LCD.h"
#include "STD_TYPES.h"
#include "DIO.h"
#define F_CPU 16000000UL
#include <util/delay.h>

void LCD_INIT(void)
{
	PIN_MODE(LCD_RS_PIN,OUTPUT);
	PIN_MODE(LCD_EN_PIN,OUTPUT);
	#if LCD_MODE       ==     _8_BIT_MODE
	PORT_MODE(LCD_DATA_PORT,OUTPUT);
	_delay_ms(100);
	LCD_WRITE_CMD(0x38);   /***_THIS_COMMAND_TO_SELECT_8_BIT_MODE_*********************/
    #elif LCD_MODE    ==     _4_BIT_MODE
	PIN_MODE(LCD_DATA_PIN_4,OUTPUT);
	PIN_MODE(LCD_DATA_PIN_5,OUTPUT);
	PIN_MODE(LCD_DATA_PIN_6,OUTPUT);
	PIN_MODE(LCD_DATA_PIN_7,OUTPUT);
	_delay_ms(100);
	LCD_WRITE_CMD(0x33);   /***_THESE_3_COMMAND_TO_SELECT_4_BIT_MODE_******************/
	LCD_WRITE_CMD(0x32);
	LCD_WRITE_CMD(0x28);	
	#endif
	LCD_WRITE_CMD(0X0C);   /***_THIS_COMMAND_TO_TURN_ON_DISPLAY_AND_TURN_OFF_CURSOR_***/
	LCD_WRITE_CMD(0X01);   /***_THIS_COMMAND_TO_CLEAR_LCD_*****************************/
	LCD_WRITE_CMD(0X06);   /***_THIS_COMMAND_TO_MOVE_CURSOR_FROM_LEFT_TO_RIGHT_********/
	LCD_WRITE_CMD(0X02);   /***_THIS_COMMAND_TO_RETURN_HOME_***************************/
}
void LCD_WRITE_CMD(u8 command)
{
	#if LCD_MODE       ==     _8_BIT_MODE
	//to select command register
	PIN_WRITE(LCD_RS_PIN,LOW);
	PORT_WRITE(LCD_DATA_PORT,command);
	//to make enable pin high
	PIN_WRITE(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	//to make enable pin low
	PIN_WRITE(LCD_EN_PIN,LOW);
	_delay_ms(5);
	#elif LCD_MODE    ==     _4_BIT_MODE
	//to select command register
	PIN_WRITE(LCD_RS_PIN,LOW);
	/*to send the left half byte*/
	PORT_WRITE(LCD_DATA_PORT,(((command >> 1) & (0b01111000))|(PORT_READ(LCD_DATA_PORT) & 0b10000111)));
	//to make enable pin high
	PIN_WRITE(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	//to make enable pin low
	PIN_WRITE(LCD_EN_PIN,LOW);
	//_delay_ms(1);
	/*to send the right half byte*/
	PORT_WRITE(LCD_DATA_PORT,(((command << 3) & (0b01111000))|(PORT_READ(LCD_DATA_PORT) & 0b10000111)));
	//to make enable pin high
	PIN_WRITE(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	//to make enable pin low
	PIN_WRITE(LCD_EN_PIN,LOW);
    _delay_ms(5);
	#endif
}
void LCD_WRITE_CHR(u8 character)
{
	#if LCD_MODE       ==     _8_BIT_MODE
	//to select data register
	PIN_WRITE(LCD_RS_PIN,HIGH);
	PORT_WRITE(LCD_DATA_PORT,character);
	//to make enable pin high
	PIN_WRITE(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	//to make enable pin low
	PIN_WRITE(LCD_EN_PIN,LOW);
	_delay_ms(5);
	#elif LCD_MODE    ==     _4_BIT_MODE
	//to select data register
	PIN_WRITE(LCD_RS_PIN,HIGH);
	/*to send the left half byte*/
	PORT_WRITE(LCD_DATA_PORT,(((character >> 1) & (0b01111000))|(PORT_READ(LCD_DATA_PORT) & 0b10000111)));
	//to make enable pin high
	PIN_WRITE(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	//to make enable pin low
	PIN_WRITE(LCD_EN_PIN,LOW);
	//_delay_ms(1);
	/*to send the right half byte*/
	PORT_WRITE(LCD_DATA_PORT,(((character << 3) & (0b01111000))|(PORT_READ(LCD_DATA_PORT) & 0b10000111)));
	//to make enable pin high
	PIN_WRITE(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	//to make enable pin low
	PIN_WRITE(LCD_EN_PIN,LOW);
	_delay_ms(5);
	#endif
}
void LCD_WRITE_STR(u8*p)
{
	while(*p)
	{
		LCD_WRITE_CHR(*p);
		p++;
	}
}
 static void LCD_WRITE_INT(u32 number) 
{
	s8 i = 0;
	u8 arr [10] = {0};
	while(number != 0)
	{
		arr[i] = number % 10;
		i++;
		number /= 10;
	}
	i--;
	while(i >= 0)
	{
		LCD_WRITE_CHR(arr[i] + 48);
		i--;
	}
}

void LCD_WRITE_NUM(s32 number)
{
	if (number == 0)
	{
		LCD_WRITE_CHR('0');
	}
	else if(number > 0)
	{
		LCD_WRITE_INT(number);
	}
	else if (number < 0)
	{
		LCD_WRITE_CHR('-');
		number *= -1;
		LCD_WRITE_INT(number);
	}
}
void LCD_CLR(void)
{
	LCD_WRITE_CMD(0x01);
}
void LCD_GOTO(u8 row,u8 col)
{
	u8 arr [2] = {0x80 , 0xC0};
	LCD_WRITE_CMD(arr[row] + col);
}
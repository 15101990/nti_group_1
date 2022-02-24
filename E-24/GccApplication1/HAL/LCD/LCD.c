/*
 * LCD.c
 *
 * Created: 11/12/2021 02:03:55 م
 *  Author: dell
 */ 
#include "LCD_CFG.h"
#include "DIO.h"
#include "STD.h"
#include "LCD.h"
#include "REG.h"
#define F_CPU 16000000
#include <util/delay.h>

void LCD_INIT(void)
{
	PIN_MODE(LCD_RS_PIN,OUTPUT);
	PIN_MODE(LCD_EN_PIN,OUTPUT);
	PIN_MODE(LCD_RW_PIN,OUTPUT);
	PIN_WRITE(LCD_RW_PIN,LOW);
	#if LCD_MODE  ==   _8_BIT_MODE
	PORT_MODE(LCD_DATA_PORT,OUTPUT);
	LCD_SEND_CMD(0X38);
	#elif LCD_MODE  == _4_BIT_MODE
	PIN_MODE(LCD_DATA_PIN_4,OUTPUT);
	PIN_MODE(LCD_DATA_PIN_5,OUTPUT);
	PIN_MODE(LCD_DATA_PIN_6,OUTPUT);
	PIN_MODE(LCD_DATA_PIN_7,OUTPUT);
	LCD_SEND_CMD(0X33);
	LCD_SEND_CMD(0X32);
	LCD_SEND_CMD(0X28);
	#endif	
	LCD_SEND_CMD(0X0C);   /***_THIS_COMMAND_TO_TURN_ON_DISPLAY_AND_TURN_OFF_CURSOR_***/
	LCD_SEND_CMD(0X01);   /***_THIS_COMMAND_TO_CLEAR_LCD_*****************************/
	LCD_SEND_CMD(0X06);   /***_THIS_COMMAND_TO_MOVE_CURSOR_FROM_LEFT_TO_RIGHT_********/
	LCD_SEND_CMD(0X02);   /***_THIS_COMMAND_TO_RETURN_HOME_***************************/
}
void LCD_SEND_CHR(u8 character)
{
	#if LCD_MODE   ==  _8_BIT_MODE
	PIN_WRITE(LCD_RS_PIN,HIGH);
	PORT_WRITE(LCD_DATA_PORT,character);
	PIN_WRITE(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	PIN_WRITE(LCD_EN_PIN,LOW);	
	_delay_ms(10);
	#elif  LCD_MODE   == _4_BIT_MODE
	PIN_WRITE(LCD_RS_PIN,HIGH);
	PORT_WRITE(LCD_DATA_PORT,(character & 0xF0)|(PORT_READ(A) & 0x0F));
	PIN_WRITE(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	PIN_WRITE(LCD_EN_PIN,LOW);
	_delay_ms(10);
	PORT_WRITE(LCD_DATA_PORT,(character << 4)|(PORT_READ(A) & 0x0F));
	PIN_WRITE(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	PIN_WRITE(LCD_EN_PIN,LOW);	
	_delay_ms(10);
	#endif
	
}

void LCD_SEND_CMD(u8 command) 
{
	#if LCD_MODE   == _8_BIT_MODE
	PIN_WRITE(LCD_RS_PIN,LOW);
	PORT_WRITE(LCD_DATA_PORT,command);
	PIN_WRITE(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	PIN_WRITE(LCD_EN_PIN,LOW);
	_delay_ms(10);
	#elif LCD_MODE == _4_BIT_MODE
	PIN_WRITE(LCD_RS_PIN,LOW);
	PORT_WRITE(LCD_DATA_PORT,(command & 0xF0)|(PORT_READ(A) & 0x0F));
	PIN_WRITE(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	PIN_WRITE(LCD_EN_PIN,LOW);
	_delay_ms(10);
	PORT_WRITE(LCD_DATA_PORT,(command << 4)|(PORT_READ(A) & 0x0F));
	PIN_WRITE(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	PIN_WRITE(LCD_EN_PIN,LOW);
	_delay_ms(10);	
	#endif
}

void LCD_SEND_STR(u8*p)
{
	u8 i = 0;
	while(p[i]  != '\0')
	{
		LCD_SEND_CHR(p[i]);
		i++;
	}
}
void LCD_WRITE_INT (u32 num)
{
	u32 rem = 0;
	u8 arr [16];
	s8 i = 0;
	while(num != 0)
	{
		rem = num % 10;
		arr[i] = rem + 48;
		i++;
		num = num / 10;
	}
	i--;
	while(i > -1)
	{
		LCD_SEND_CHR(arr[i]);
		i--;
	}
}
void LCD_CLR(void)
{
	LCD_SEND_CMD(0X01);	
}
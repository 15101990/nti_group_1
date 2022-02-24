/*
 * DIO.c
 *
 * Created: 04/12/2021 02:02:24 م
 *  Author: dell
 */ 

#include "DIO.h"
#include "REG.h"
#include "BIT_MATH.h"

void PIN_MODE(u8 x,u8 state)
{
	u8 pin  = x % 10;
	u8 port = x / 10;
	switch(state)
	{
		case INPUT:
		switch(port)
		{
			case 0:
			CLR_BIT(DDRA,pin);
			break;
			case 1:
			CLR_BIT(DDRB,pin);
			break;
			case 2:
			CLR_BIT(DDRC,pin);
			break;
			case 3:
			CLR_BIT(DDRD,pin);
			break;
			default:
			break;
		}
		break;
		case OUTPUT:
		switch(port)
		{
			case 0:
			SET_BIT(DDRA,pin);
			break;
			case 1:
			SET_BIT(DDRB,pin);
			break;
			case 2:
			SET_BIT(DDRC,pin);
			break;
			case 3:
			SET_BIT(DDRD,pin);
			break;
			default:
			break;
		}
		break;
		default:
		break;
	}
}

 void PIN_WRITE(u8 x,u8 state)
{
	u8 pin  = x % 10;
	u8 port = x / 10;
	switch(state)
	{
		case LOW:
		switch(port)
		{
			case 0:
			CLR_BIT(PORTA,pin);
			break;
			case 1:
			CLR_BIT(PORTB,pin);
			break;
			case 2:
			CLR_BIT(PORTC,pin);
			break;
			case 3:
			CLR_BIT(PORTD,pin);
			break;
			default:
			break;
		}
		break;
		case HIGH:
		switch(port)
		{
			case 0:
			SET_BIT(PORTA,pin);
			break;
			case 1:
			SET_BIT(PORTB,pin);
			break;
			case 2:
			SET_BIT(PORTC,pin);
			break;
			case 3:
			SET_BIT(PORTD,pin);
			break;
			default:
			break;
		}
		break;
		default:
		break;
	}
}
u8   PIN_READ(u8 x)
{
	u8 pin  = x % 10;
	u8 port = x / 10;
	u8 reading = 0;
		switch(port)
		{
			case 0:
			reading = GET_BIT(PINA,pin);
			break;
			case 1:
			reading = GET_BIT(PINB,pin);
			break;
			case 2:
			reading = GET_BIT(PINC,pin);
			break;
			case 3:
			reading = GET_BIT(PIND,pin);
			break;
			default:
			break;
		}
		return reading;	
}
void PIN_TOGGLE(u8 x)
{
	u8 pin  = x % 10;
	u8 port = x / 10;
	switch(port)
	{
		case 0:
		TOG_BIT(PORTA,pin);
		break;
		case 1:
		TOG_BIT(PORTB,pin);
		break;
		case 2:
		TOG_BIT(PORTC,pin);
		break;
		case 3:
		TOG_BIT(PORTD,pin);
		break;
		default:
		break;
	}	
}
void PORT_MODE(u8 port,u8 state)
{
	switch(state)
	{
		case INPUT:
		switch(port)
		{
			case A:
			DDRA = 0;
			break;
			case B:
			DDRB = 0;
			break;	
			case C:
			DDRC = 0;
			break;
			case D:
			DDRD = 0;
			break;
			default:
			break;
		}
		break;
		case OUTPUT:
		switch(port)
		{
			case A:
			DDRA = 255;
			break;
			case B:
			DDRB = 255;
			break;
			case C:
			DDRC = 255;
			break;
			case D:
			DDRD = 255;
			break;
			default:
			break;
		}
		break;
		default:
		break;
	}
}
void PORT_WRITE(u8 port,u8 value)
{
	switch(port)
	{
		case A:
		PORTA = value;
		break;
		case B:
		PORTB = value;
		break;
		case C:
		PORTC = value;
		break;
		case D:
		PORTD = value;
		break;
		default:
		break;
	}
}

u8   PORT_READ(u8 port)
{
	u8 value = 0;
	switch(port)
	{
		case A:
		value = PORTA;
		break;
		case B:
		value = PORTB;
		break;
		case C:
		value = PORTC;
		break;
		case D:
		value = PORTD;
		break;
		default:
		break;
	}
	return value;
}

void PIN_PULL_UP_RES(u8 x,u8 state)
{
	
	u8 pin  = x % 10;
	u8 port = x / 10;
	switch(state)
	{
		case DISABLE:
		switch(port)
		{
			case 0:
			CLR_BIT(PORTA,pin);
			break;
			case 1:
			CLR_BIT(PORTB,pin);
			break;
			case 2:
			CLR_BIT(PORTC,pin);
			break;
			case 3:
			CLR_BIT(PORTD,pin);
			break;
			default:
			break;
		}
		break;
		case ENABLE:
		switch(port)
		{
			case 0:
			SET_BIT(PORTA,pin);
			break;
			case 1:
			SET_BIT(PORTB,pin);
			break;
			case 2:
			SET_BIT(PORTC,pin);
			break;
			case 3:
			SET_BIT(PORTD,pin);
			break;
			default:
			break;
		}
		break;
		default:
		break;
	}	
}
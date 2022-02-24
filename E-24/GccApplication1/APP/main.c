/*
 * GccApplication1.c
 *
 * Created: 03/12/2021 02:36:04 م
 * Author : dell
 */ 

#include "LED.h"
#include "P_B.h"
#include "SSD.h"
#include "LCD.h"
#include "STEPPER.h"
#include "KEY_PAD.h"
#include "EXT_INT.h"
#include "LM35.h"
#include "TIMERS.h"
#include "DC_MOTOR.h"
#include "WDT.h"
#include "UART.h"
#include "SPI.h"
#include "EEPROM.h"
#include <avr/interrupt.h>
#define F_CPU 16000000
#include <util/delay.h>

extern u32 no_of_ov;
extern u8  rem_ticks;
extern u32 no_of_cm;
int main(void)
{
	LED_INIT(LED_0);
	EEPROM_INIT();
	
	SSD_INIT();
	u8 x = EEPROM_READ(0,6);
	

    while (1)
    {
		SSD_DISPLAY(x);
		x++;
		EEPROM_WRITE(x,0,6);  // data,page number,byte number
		_delay_ms(500);
	}
}
/*
ISR(INT0_vect)
{
	LED_OFF();
	_delay_ms(1000);
}
*/
/*
ISR(TIMER0_OVF_vect)
{
	static u16 counter = 0;
	counter++;
	if(counter == no_of_ov)
	{
		LED_TOG(LED_0);
		counter = 0;
		TCNT0 = 256 - rem_ticks;
	}
}
*/
/*
ISR(TIMER0_COMP_vect)
{
	static u16 counter = 0;
	counter++;
	if(counter == no_of_cm)
	{
		LED_TOG(LED_0);
		counter = 0;
	}	
}
*/
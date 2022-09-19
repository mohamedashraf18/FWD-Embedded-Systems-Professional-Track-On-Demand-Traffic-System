/*
 * led.c
 *
 * Created: 9/11/2022 4:06:42 PM
 *  Author: Kimo Store
 */ 


#include "led.h" 

void LED_init    (u8 ledport , u8 ledpin){
	
	DIO_SetPinDirection(ledport,ledpin,DIO_PIN_OUTPUT);   /*led is an output device*/
}

void LED_on      (u8 ledport , u8 ledpin){
	
	DIO_SetPinValue(ledport,ledpin,DIO_PIN_HIGH);
}

void LED_off     (u8 ledport , u8 ledpin){
	
	DIO_SetPinValue(ledport,ledpin,DIO_PIN_LOW);
}

void LED_toggle  (u8 ledport , u8 ledpin){
	
	DIO_TogglePinValue(ledport,ledpin);
}

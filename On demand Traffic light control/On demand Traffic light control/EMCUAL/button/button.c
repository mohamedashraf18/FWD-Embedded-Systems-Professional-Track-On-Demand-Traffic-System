/*
 * button.c
 *
 * Created: 9/11/2022 4:46:42 PM
 *  Author: Kimo Store
 */ 

#include "button.h"


void BUTTON_init (u8 buttonport , u8 buttonpin){
	
	DIO_SetPinDirection(buttonport,buttonpin,DIO_PIN_INPUT);  /*BUTTON IS AN INPUT DEVICE*/
}

void BUTTON_read (u8 buttonport , u8 buttonpin , u8 *value){
	
	DIO_GetPinValue (buttonport,buttonpin,value);
}
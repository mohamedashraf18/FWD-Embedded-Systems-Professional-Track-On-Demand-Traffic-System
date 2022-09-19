/*
 * button.h
 *
 * Created: 9/11/2022 4:46:26 PM
 *  Author: Kimo Store
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO/DIO_interface.h"

/* #define BUTTON_1_PORT  write here the port where you connected button1 to */
/* #define BUTTON_1_PIN   write here the pin where you connected button1 to  */
 
void BUTTON_init (u8 buttonport , u8 buttonpin);

void BUTTON_read (u8 buttonport , u8 buttonpin , u8 *value);


#endif /* BUTTON_H_ */
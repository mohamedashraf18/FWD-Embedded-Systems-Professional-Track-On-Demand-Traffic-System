/*
 * led.h
 *
 * Created: 9/11/2022 4:06:56 PM
 *  Author: Kimo Store
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO/DIO_interface.h"

void LED_init    (u8 ledport , u8 ledpin);
void LED_on      (u8 ledport , u8 ledpin);
void LED_off     (u8 ledport , u8 ledpin);
void LED_toggle  (u8 ledport , u8 ledpin);



#endif /* LED_H_ */
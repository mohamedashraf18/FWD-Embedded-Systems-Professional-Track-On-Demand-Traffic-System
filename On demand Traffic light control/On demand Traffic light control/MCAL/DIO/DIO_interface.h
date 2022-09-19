/*
 * DIO_interface.h
 *
 * Created: 9/3/2022 11:38:19 AM
 *  Author: Kimo Store
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
#include "../../utiles/BIT_MATH.h"
#include "../../utiles/ATMEGA32_REG.h"
             /*PinDirection*/
#define DIO_PIN_OUTPUT 1
#define DIO_PIN_INPUT 0
              /*PortId*/
#define DIO_PORTA   0
#define DIO_PORTB   1
#define DIO_PORTC   2
#define DIO_PORTD   3
              /*PinId*/
#define DIO_PIN0   0
#define DIO_PIN1   1
#define DIO_PIN2   2
#define DIO_PIN3   3
#define DIO_PIN4   4
#define DIO_PIN5   5
#define DIO_PIN6   6
#define DIO_PIN7   7
             /*pin value*/
#define  DIO_PIN_HIGH  1
#define  DIO_PIN_LOW   0
                 /*PIN APIS*/
void DIO_SetPinDirection   (u8 PortId,u8 PinId,u8 PinDirection);
void DIO_SetPinValue       (u8 PortId,u8 PinId,u8 PinValue);
void DIO_GetPinValue       (u8 PortId,u8 PinId,u8* PinValue);
void DIO_TogglePinValue    (u8 PortId,u8 PinId);
#endif /* DIO_INTERFACE_H_ */
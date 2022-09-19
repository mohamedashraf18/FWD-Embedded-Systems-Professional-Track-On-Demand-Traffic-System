/*
 * ATMEGA32_REG.h
 *
 * Created: 9/3/2022 11:57:06 AM
 *  Author: Kimo Store
 */ 


#ifndef ATMEGA32_REG_H_
#define ATMEGA32_REG_H_

#include "DATA_TYPES.h"

                                    /*DIO REGISTERs*/

       /* DATA DIRECTION REGISTERs*/

#define DDRA   *((volatile u8*)0x3A)      /*0x3A is an address*/
#define DDRB   *((volatile u8*)0x37)
#define DDRC   *((volatile u8*)0x34)
#define DDRD   *((volatile u8*)0x31)


       /*OUTPUT REGISTERs*/

#define PORTA   *((volatile u8*)0x3B)
#define PORTB   *((volatile u8*)0x38)
#define PORTC   *((volatile u8*)0x35)
#define PORTD   *((volatile u8*)0x32)


       /*INPUT REGISTERs*/

#define PINA   *((volatile u8*)0x39)
#define PINB   *((volatile u8*)0x36)
#define PINC   *((volatile u8*)0x33)
#define PIND   *((volatile u8*)0x30)

                           /* TIMER0 REGISTERS */
						   
#define TCCR0   *((volatile u8*)0x53)
#define TCNT0   *((volatile u8*)0x52)
#define TIFR    *((volatile u8*)0x58)						   
						   



#endif /* ATMEGA32_REG_H_ */
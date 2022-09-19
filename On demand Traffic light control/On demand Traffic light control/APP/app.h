/*
 * app.h
 *
 * Created: 9/12/2022 5:56:33 PM
 *  Author: Kimo Store
 */ 


#ifndef APP_H_
#define APP_H_

#include "../EMCUAL/led/led.h"
#include "../EMCUAL/button/button.h"

#define NUMBER_OF_OVERFLOWS  19532    /*DEDUCED FROM OUR TIMER CALCULATIONS*/
#define NUMBER_OF_OVERFLOWS1  20      /*DEDUCED FROM OUR TIMER CALCULATIONS*/
#define NUMBER_OF_OVERFLOWS2  1000    /*DEDUCED FROM OUR TIMER CALCULATIONS*/

void APP_init  (void);
void APP_start (void);



#endif /* APP_H_ */
/*
 * On demand Traffic light control.c
 *
 * Created: 9/12/2022 5:24:50 PM
 * Author : Kimo Store
 */ 

#include <avr/interrupt.h>
#include "APP/app.h"              

int main(void)
{
    /* Replace with your application code */
	
	APP_init();
	APP_start();
   
}
ISR(INT0_vect)  /*THIS PIECE OF CODE WILL NOT BE TRIGGERED UNTIL THE BUTTON IS PRESSED*/
{   /*variable to store the value of cars' red led*/
	static unsigned int value;
	unsigned int overflowcounter  = 0;
	unsigned int overflowcounter1 = 0;
	DIO_GetPinValue   (DIO_PORTA,DIO_PIN0,&value);
	if(value == DIO_PIN_LOW ) /*MEANS THAT CARS' RED LIGHT IS OFF WHICH MEANS CARS' GREEN OR YELLOW LIGHT IS MAYBE ON */
	{   /*YELLOW LIGHTS ARE OFF INCASE THEY WERE ON*/
		LED_off(DIO_PORTA,DIO_PIN1); 
		LED_off(DIO_PORTB,DIO_PIN1);
		/*CARS' GREEN LIGHT AND PEDESTRIANS' RED LIGHT ARE BOTH OFF INCASE THEY WERE ON*/
		LED_off(DIO_PORTA,DIO_PIN2);
		LED_off(DIO_PORTB,DIO_PIN0);
		 /* yellow light in cars and pedestrians blinks */
		 while( overflowcounter <  NUMBER_OF_OVERFLOWS1 )
		 {
			 LED_toggle(DIO_PORTA,DIO_PIN1);
			 LED_toggle(DIO_PORTB,DIO_PIN1);
			 while(overflowcounter1 < NUMBER_OF_OVERFLOWS2 )
			 {
				 /* WAIT UNTIL THE OVERFLOW FLAG TO BE SET */
				 while ( (TIFR & (1<<0)) == 0 );
				 /* CLEAR THE OVERFLOW FLAG*/
				 SET_BIT(TIFR,0);
				 overflowcounter1++;
			 }
			 overflowcounter1 = 0;
			 TCNT0 = 0x00;
			 overflowcounter++;
		 }
		 overflowcounter = 0;
		 TCNT0 = 0x00;
		 /*CARS yellow LIGHT IS OFF AND PEDESTRIANS yellow LIGHT IS OFF*/
		 LED_off(DIO_PORTA,DIO_PIN1);
		 LED_off(DIO_PORTA,DIO_PIN1);
	}
	/*DISABLE THE EXTERNAL INTERRUPT INT0*/
	CLR_BIT(GICR,INT0);
	/*RETURN TO THE NORMAL MODE OF THE TRAFFIC SYSTEM UNTIL ANOTHER INTERFERENCE OF THE BUTTON*/
	APP_start();}

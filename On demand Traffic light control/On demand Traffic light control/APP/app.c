/*
 * app.c
 *
 * Created: 9/12/2022 5:57:01 PM
 *  Author: Kimo Store
 */ 

#include "app.h"
#include <avr/interrupt.h>



void APP_init  (void){
	
	/*the button is an input device*/
	
	BUTTON_init(DIO_PORTD,DIO_PIN2);
	
	/*the leds are output devices*/
	
	LED_init(DIO_PORTA,DIO_PIN0);
	LED_init(DIO_PORTA,DIO_PIN1);
	LED_init(DIO_PORTA,DIO_PIN2);
	
	LED_init(DIO_PORTB,DIO_PIN0);
	LED_init(DIO_PORTB,DIO_PIN1);
	LED_init(DIO_PORTB,DIO_PIN2);
	
}

void APP_start (void){
	
	unsigned int overflowcounter = 0;
	unsigned int overflowcounter1 = 0;
	
	/*enable global interrupt*/
	sei();
	
	/* set interrupt sense to rising edge */
	MCUCR |= (1<<ISC00) | (1<<ISC01);
	
	/*enable external interrupt INT0*/
	SET_BIT(GICR,INT0);
	
	/*CHOOSE TIMER MODE */
	TCCR0 = 0x00; /*NORMAL MODE*/
	
	/*TIMER SET INITIAL VALUE*/
	TCNT0 = 0x00;
	
	/*TIMER START*/
	SET_BIT(TCCR0,0); /*NO PRESCALER*/
		
	while (1)
	{
		 /*INITIALLY CARS RED LIGHT IS ON WHILE PEDESTRIANS GREEN LIGHT IS ON*/
		 LED_on(DIO_PORTA,DIO_PIN0);
		 LED_on(DIO_PORTB,DIO_PIN2);
		 
		 while ( overflowcounter <  NUMBER_OF_OVERFLOWS ){
			 
			 /* WAIT UNTIL THE OVERFLOW FLAG TO BE SET */
			 while ( (TIFR & (1<<0)) == 0 );
			 
			 /* CLEAR THE OVERFLOW FLAG*/
			 SET_BIT(TIFR,0);
			 
			 overflowcounter++;
		 }
		 
		 overflowcounter = 0;
		 
		 TCNT0 = 0x00;
		 
		 /*CARS RED LIGHT IS OFF PEDESTRIANS GREEN LIGHT IS OFF*/
		 LED_off(DIO_PORTA,DIO_PIN0);
		 LED_off(DIO_PORTB,DIO_PIN2);
		 
/***********************************************************************************************************************************************/
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
		 
	/*************************************************************************************************************************************/	 
		  /* CARS green LIGHT IS ON WHILE PEDESTRIANS red LIGHT IS ON*/
		  LED_on(DIO_PORTA,DIO_PIN2);
		  LED_on(DIO_PORTB,DIO_PIN0);
		  
		  while ( overflowcounter <  NUMBER_OF_OVERFLOWS ){
			  
			  /* WAIT UNTIL THE OVERFLOW FLAG TO BE SET */
			  while ( (TIFR & (1<<0)) == 0 );
			  
			  /* CLEAR THE OVERFLOW FLAG*/
			  SET_BIT(TIFR,0);
			  
			  overflowcounter++;
		  }
		  
		  overflowcounter = 0;
		  
		  TCNT0 = 0x00;
		  
		  /*CARS green LIGHT IS OFF PEDESTRIANS red LIGHT IS OFF*/
		  LED_off(DIO_PORTA,DIO_PIN2);
		  LED_off(DIO_PORTB,DIO_PIN0);
	/*****************************************************************************************************************************************/	  
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
		   
		   /*CARS yellow LIGHT IS OFF PEDESTRIANS yellow LIGHT IS OFF*/
		   LED_off(DIO_PORTA,DIO_PIN1);
		   LED_off(DIO_PORTA,DIO_PIN1);
		 
		
		 
	}
	
	
	
	
	
	
}

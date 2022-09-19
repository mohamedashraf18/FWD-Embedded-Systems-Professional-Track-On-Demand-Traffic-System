/*
 * DIO_program.c
 *
 * Created: 9/3/2022 11:37:26 AM
 *  Author: Kimo Store
 */ 



#include "DIO_interface.h"


                                /*PIN APIS*/
								
								
void DIO_SetPinDirection   (u8 PortId,u8 PinId,u8 PinDirection){        /*DEALS WITH DATA DIRECTION REGISTER*/
	if((PortId<=3)&&(PinId<=7)&&(PinDirection<=1)){  /*WE USED THIS IF CONDITION TO MAKE SURE THE PortId,PinId AND PinDirection IS NOT OUT OF RANGE*/
		switch(PortId)
		{  case DIO_PORTA:
			if(PinDirection == DIO_PIN_OUTPUT){ /*WE USED THIS IF CONDITION TO MAKE OUR CODE GENERIC AS POSSIBLE SO WE CAN USE IT EVEN IF WE USED NEGATIVE LOGIC */
				SET_BIT(DDRA,PinId);
			}
			else{
				CLR_BIT(DDRA,PinId);
			}
			break;
			case DIO_PORTB:
			if(PinDirection == DIO_PIN_OUTPUT){
				SET_BIT(DDRB,PinId);
			}
			else{
				CLR_BIT(DDRB,PinId);
			}
			break;
			case DIO_PORTC:
			if(PinDirection == DIO_PIN_OUTPUT){
				SET_BIT(DDRC,PinId);
			}
			else{
				CLR_BIT(DDRC,PinId);
			}
			
			break;
			case DIO_PORTD:
			if(PinDirection == DIO_PIN_OUTPUT){
				SET_BIT(DDRD,PinId);
			}
			else{
				CLR_BIT(DDRD,PinId);
			}
			
			break;
		}
		
	}
	
	
}
void DIO_SetPinValue       (u8 PortId,u8 PinId,u8 PinValue){    /*DEALS WITH OUTPUT REGISTER*/
	
	if( (PortId<=3) && (PinId<=7) && (PinValue<=1) ){
		
		switch(PortId){
			
			case DIO_PORTA :
			
			if(PinValue == DIO_PIN_HIGH ){
				
				SET_BIT(PORTA,PinId);
				
			}
			else {
				CLR_BIT(PORTA,PinId);
			}
			break;
			
			case DIO_PORTB :
			
			if(PinValue == DIO_PIN_HIGH ){
				
				SET_BIT(PORTB,PinId);
				
			}
			else {
				CLR_BIT(PORTB,PinId);
			}
			break;
			
			case DIO_PORTC :
			
			if(PinValue == DIO_PIN_HIGH ){
				
				SET_BIT(PORTC,PinId);
				
			}
			else {
				CLR_BIT(PORTC,PinId);
			}
			break;
			
			case DIO_PORTD :
			
			if(PinValue == DIO_PIN_HIGH ){
				
				SET_BIT(PORTD,PinId);
				
			}
			else {
				CLR_BIT(PORTD,PinId);
			}
			break;
			
		}
		
		
	}
	
	
}

void DIO_GetPinValue       (u8 PortId,u8 PinId,u8* PinValue){       /* DEALS WITH INPUT REGISTER 
																	* AND IT CAN DEAL WITH OUTPUT REGISTER IF WE WANT TO MAKE SURE OF THE VALUE WE OUTPUT FOR SOME REASON */
	
	if( (PortId<=3) && (PinId<=7) && (PinValue!=NULL) ){
		
		switch(PortId){
			
			case DIO_PORTA:
			
			if (GET_BIT(PINA,PinId) == DIO_PIN_HIGH){
				
				*PinValue = DIO_PIN_HIGH;
				
			}
			else {
				*PinValue = DIO_PIN_LOW;
			}
			
			break;
			case DIO_PORTB:
			
			if (GET_BIT(PINB,PinId) == DIO_PIN_HIGH){
				
				*PinValue = DIO_PIN_HIGH;
				
			}
			else {
				*PinValue = DIO_PIN_LOW;
			}
			
			break;
			case DIO_PORTC:
			
			if (GET_BIT(PINC,PinId) == DIO_PIN_HIGH){
				
				*PinValue = DIO_PIN_HIGH;
				
			}
			else {
				*PinValue = DIO_PIN_LOW;
			}
			
			break;
			case DIO_PORTD:
			
			if (GET_BIT(PIND,PinId) == DIO_PIN_HIGH){
				
				*PinValue = DIO_PIN_HIGH;
				
			}
			else {
				*PinValue = DIO_PIN_LOW;
			}
			
			break;
			
		}
		
		
		
	}
	
}


void DIO_TogglePinValue    (u8 PortId,u8 PinId){
	if( (PortId<=3)&&(PinId<=7) ){
		
		switch(PortId){
			
			case DIO_PORTA :
			
			TOG_BIT(PORTA,PinId);
			
			
			break;
			
			case DIO_PORTB :
			
			TOG_BIT(PORTB,PinId);
			
			
			break;
			
			case DIO_PORTC :
			
			TOG_BIT(PORTC,PinId);
			
			
			break;
			
			case DIO_PORTD :
			
			TOG_BIT(PORTD,PinId);
			
			
			break;
			
			
		}
	}
	
}


  




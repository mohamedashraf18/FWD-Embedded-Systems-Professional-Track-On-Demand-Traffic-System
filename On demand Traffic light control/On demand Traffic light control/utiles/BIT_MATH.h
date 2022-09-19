


#ifndef BIT_MATH_H_INCLUDED
#define BIT_MATH_H_INCLUDED

									/* THESE FUNCTIONS ARE FUNCTIONLIKE MACRO */
									
#define SET_BIT(REG,BIT_NUM)	REG|=(1<<BIT_NUM)       /*       writes 1        */  
#define CLR_BIT(REG,BIT_NUM)	REG&=(~(1<<BIT_NUM))    /*       writes 0        */
#define TOG_BIT(REG,BIT_NUM)	REG^=(1<<BIT_NUM)       /* inverts the bit value */
#define GET_BIT(REG,BIT_NUM)	((REG>>BIT_NUM)&1)      /* reads the bit value   */ 
														/* GET_BIT  RETURNS A VALUE UNLIKE THE 3 FUNCTIONS ABOVE
														 * SO THIS VALUE MUST BE USED WITH LOGIC OPERATORS FOR COMPARING 
														 * OR PUT INSIDE A VARIABLE    */

#endif 
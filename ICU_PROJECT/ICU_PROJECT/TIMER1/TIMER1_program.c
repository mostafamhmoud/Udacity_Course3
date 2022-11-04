/*
 * TIMER1_program.c
 *
 *  Created on: Aug 22, 2022
 *      Author: abdelrahmanhossam
 */


#include "../EXTRA/STD_TYPES.h"
#include "../EXTRA/BIT_MATH.h"

#include "TIMER1_private.h"
#include "TIMER1_configuration.h"
#include "TIMER1_interface.h"

void MTIMERS_voidTimer1Init(void)
{
	/*Select Timer 1 mode ==> 14*/
	SET_BIT(TCCR1A,1);
	CLR_BIT(TCCR1A,0);
	SET_BIT(TCCR1B,4);
	SET_BIT(TCCR1B,3);
	/* Select HW Action on OC1A pin => Non Inverting */
	SET_BIT(TCCR1A,7);
	CLR_BIT(TCCR1A,6);

	/* Set top value in ICR1 */
	ICR1=19999;

	/* set angle of servo motor */
	OCR1A=1500;

	/*Set prescaler*/
	CLR_BIT(TCCR1B,2);
	SET_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,0);

}

void MTIMERS_voidSetCR1AValue(u8 A_u8Value)
{
	OCR1A=A_u8Value;
}

void MTIMERS_voidSetTimerValue(u16 A_u16Value){
	TCNT1 = A_u16Value;
}

u16 MTIMERS_voidGetTimer1Value(){
	return TCNT1 ;
}

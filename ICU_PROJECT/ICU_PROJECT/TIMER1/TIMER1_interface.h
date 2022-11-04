/*
 * TIMER1_interface.h
 *
 *  Created on: Aug 22, 2022
 *      Author: abdelrahmanhossam
 */

#ifndef INCLUDE_MCAL_TIMER1_TIMER1_INTERFACE_H_
#define INCLUDE_MCAL_TIMER1_TIMER1_INTERFACE_H_
#include "../EXTRA/STD_TYPES.h"


void MTIMERS_voidTimer1Init(void);

void MTIMERS_voidSetCR1AValue(u8 A_u8Value);
u16 MTIMERS_voidGetTimer1Value();
void MTIMERS_voidSetTimerValue(u16 A_u16Value);


#endif /* INCLUDE_MCAL_TIMER1_TIMER1_INTERFACE_H_ */

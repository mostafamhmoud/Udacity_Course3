/*
 * GI_program.c

 *
 *  Created on: Oct 16, 2022
 *      Author: top_system
 */

#include "../EXTRA/STD_TYPES.h"
#include "../EXTRA/BIT_MATH.h"
#include "GI_private.h"
#include "GI_configuration.h"
#include "GI_interface.h"

void MGI_voidEnable (void){
	SET_BIT(SREG,GLOBAL_INTERRUPT_ENABLE_BIT);
}
void MGI_voidDisable (void){
	CLR_BIT(SREG,GLOBAL_INTERRUPT_ENABLE_BIT);
}


/*
 * main.c

 *
 *  Created on: Oct 16, 2022
 *      Author: top_system
 */


#include "DIO/DIO_configuration.h"
#include "DIO/DIO_interface.h"
#include "DIO/DIO_interface.h"
#include "EXTI/EXTI_Interface.h"
#include "TIMER1/TIMER1_interface.h"
#include "TIMER0/TIMER0_interface.h"
#include "LCD/LCD_interface.h"
#include "GI/GI_interface.h"
void calcSignalTime(void);
u16 periodTime = 0;
u16 TON_Time = 0 ;


int main(void){
	MDIO_voidInit();
	HLCD_voidInit();
	MEXTI_voidSetCallBack(EXTI0, calcSignalTime);
	MEXTI_voidConfig(EXTI0, RISING_EDGE);
	MEXTI_voidEnable(EXTI0);
	MTIMERS_voidTimer1Init();
	MTIMER0_voidInit();
	MGI_voidEnable();

while (1){
	while(periodTime==0||TON_Time==0){
		HLCD_voidGoToPos(1, 2);
			HLCD_voidDisplayNumber(periodTime);
			HLCD_voidGoToPos(2, 2);
			HLCD_voidDisplayNumber(TON_Time);

	}


}
return 0 ;

}


void calcSignalTime(void){
	static u8 counter = 0 ;
	counter++;
	if(counter==1){
		MTIMERS_voidSetTimerValue(0);
	}
	else if (counter==2){
		periodTime = MTIMERS_voidGetTimer1Value();
		MEXTI_voidConfig(EXTI0, FALLING_EDGE);
	}
	else if (counter==3){
		TON_Time = MTIMERS_voidGetTimer1Value() - periodTime ;
		counter = 0 ;
		MEXTI_voidDisable(EXTI0);
	}
}

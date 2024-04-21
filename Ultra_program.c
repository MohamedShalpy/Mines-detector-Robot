/***********************************************************************/
/***********************************************************************/
/********************Layer :HAL******************************************/
/********************Author: Mohamed Shalpy*****************************************/
/********************Date :10 OCT 2023*********************************/
/********************Ver:01*************************************/
//                              # Ultrasonic Sensor #
/*******************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "exti_interface.h"
#include "timer1_interface.h"
#include "timer1.h"
#include "Ultra_config.h"
#include "Ultra_interface.h"
#include "Ultra_private.h"


static u16 UltraDistance = 0;  // Variable to Read the distance
static u8 UltraFlag = NO_OBSTACLE; // Variable to Read the Flag of the Mine Detector

void Ultra_voidInit(void)
{
	DIO_voidSetPinDir(Trigger_Port,TRIGGER_Pin,PIN_DIR_OUT);
	/* Set Echo Pin Input
		 * Input Pull Up
		 */
	DIO_voidSetPinDir(Echo_Port,ECHO_Pin,PIN_DIR_IN);
	DIO_voidSetPinVal(Echo_Port,ECHO_Pin,PIN_VAL_HIGH);
	TIMER1_u8SetCallBack(&Ultra_voidTriggerReading);// Run Function Trigger to run in the ISR of Timer1
	HWICU_voidSetCallBack(&Ultra_voidEchoReading); // Run Function Echo to run in the ISR of ICU
}


void Ultra_voidTriggerReading(void)
{
	static u8 LocalCounter=0;
	LocalCounter++;
	//generate trigger pulse
	if(LocalCounter==CheckTime)
	{
	DIO_voidSetPinVal(Trigger_Port,TRIGGER_Pin,PIN_VAL_HIGH);
	_delay_us(15);
	DIO_voidSetPinVal(Trigger_Port,TRIGGER_Pin,PIN_VAL_LOW);
	HWICU_voidInit();
	}
}

void Ultra_voidEchoReading(void)
{
	static u8 LocalCounter=0;
	static u16 LocalPulseStart,LocalPulseEnd;
	LocalCounter++;
	//pulse is start
	if (LocalCounter % 2 ==1)
	{
		LocalPulseStart=HWICU_u16ReadTicks();
		HWICU_voidSetTriggerEdge(FALLING_EDGE);
	}
	//pulse is end
	else
	{
		LocalPulseEnd=HWICU_u16ReadTicks();
		// Calculate the Distance
		UltraDistance =(LocalPulseEnd - LocalPulseStart)/466;
		if(UltraDistance <= MinDistance)
		{
			UltraFlag=OBSTACLE;
		}
		else
		{
			UltraFlag=NO_OBSTACLE;
		}
		HWICU_voidInterruptDisable();
	}
}

u8 Ultra_u8GetReading(void) // Function to return the obstacle flag
{
	return UltraFlag;
}

/***********************************************************************/
/***********************************************************************/
/********************Layer :HAL******************************************/
/********************Author: Mohamed Shalpy*****************************************/
/********************Date :10 OCT 2023*********************************/
/********************Ver:01*************************************/
//                              # Buzzer #
/*******************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"

#include "Buzzer.h"



void Buzzer_voidinit(void)
{
	DIO_voidSetPinDir(Buzzer_Port,Buzzer_Pin,PIN_DIR_OUT);
}
void Buzzer_voidEnable(void)
{
	DIO_voidSetPinDir(Buzzer_Port,Buzzer_Pin,PIN_VAL_HIGH);
}
void Buzzer_voidDisable(void)
{
	DIO_voidSetPinDir(Buzzer_Port,Buzzer_Pin,PIN_VAL_LOW);
}

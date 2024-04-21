/***********************************************************************/
/***********************************************************************/
/********************Layer :HAL******************************************/
/********************Author: Mohamed Shalpy*****************************************/
/********************Date :10 OCT 2023*********************************/
/********************Ver:01*************************************/
//                              # Led #
/*******************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_config.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "led.h"

void Led_voidinit(void)
{

	DIO_voidSetPinDir(Led_Port,Led_Red_Pin,PIN_DIR_OUT);
	DIO_voidSetPinDir(Led_Port,Led_Yellow_Pin,PIN_DIR_OUT);
	DIO_voidSetPinDir(Led_Port,Led_Green_Pin,PIN_DIR_OUT);
}

void Led_voidLedRedEnable(void)
{
	DIO_voidSetPinVal(Led_Port,Led_Red_Pin,PIN_VAL_HIGH);
}
void Led_voidLedGreenEnable(void)
{
	DIO_voidSetPinVal(Led_Port,Led_Green_Pin,PIN_VAL_HIGH);
}
void Led_voidLedYellowEnable(void)
{
	DIO_voidSetPinVal(Led_Port,Led_Yellow_Pin,PIN_VAL_HIGH);
}

void Led_voidLedRedDisable(void)
{
	DIO_voidSetPinVal(Led_Port,Led_Red_Pin,PIN_VAL_LOW);
}
void Led_voidLedGreenDisable(void)
{
	DIO_voidSetPinVal(Led_Port,Led_Green_Pin,PIN_VAL_LOW);
}
void Led_voidLedYellowDisable(void)
{
	DIO_voidSetPinVal(Led_Port,Led_Yellow_Pin,PIN_VAL_LOW);
}

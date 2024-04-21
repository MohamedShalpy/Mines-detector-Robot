/*
 * Motor1_program.c
 *
 *  Created on: Jan 24, 2024
 *      Author: Dell5570
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"

#include "Motor1_interface.h"
#include "Motor1_private.h"
#include "Motor1_config.h"

void Motor_voidInit(void)
{
	DIO_voidSetPortDir(Motor_Port,PORT_DIR_OUT);
}
u8 MOTOR_u8DCRot(u8 Copy_u8Direction,u8 Copy_u8Speed)
{
	u8 LocalErrorState=OK;
	// move forward
	if(Copy_u8Direction==MOTOR_Fwd)
	{
		DIO_voidSetPinVal(Motor_Port,Motor1_Pin1,PIN_VAL_LOW);
		DIO_voidSetPinVal(Motor_Port,Motor1_Pin2,PIN_VAL_HIGH);
		DIO_voidSetPinVal(Motor_Port,Motor2_Pin1,PIN_VAL_LOW);
		DIO_voidSetPinVal(Motor_Port,Motor2_Pin2,PIN_VAL_HIGH);
	}
	//move back
	else if(Copy_u8Direction==MOTOR_Back)
	{
		DIO_voidSetPinVal(Motor_Port,Motor1_Pin2,PIN_VAL_LOW);
		DIO_voidSetPinVal(Motor_Port,Motor1_Pin1,PIN_VAL_HIGH);
		DIO_voidSetPinVal(Motor_Port,Motor2_Pin2,PIN_VAL_LOW);
		DIO_voidSetPinVal(Motor_Port,Motor2_Pin1,PIN_VAL_HIGH);
	}
	//move right
	else if(Copy_u8Direction==MOTOR_Right)
	{
		DIO_voidSetPinVal(Motor_Port,Motor1_Pin1,PIN_VAL_HIGH);
		DIO_voidSetPinVal(Motor_Port,Motor1_Pin2,PIN_VAL_LOW);
		DIO_voidSetPinVal(Motor_Port,Motor2_Pin1,PIN_VAL_LOW);
		DIO_voidSetPinVal(Motor_Port,Motor2_Pin2,PIN_VAL_LOW);
	}
	//move left
	else if(Copy_u8Direction==MOTOR_Left)
	{
		DIO_voidSetPinVal(Motor_Port,Motor1_Pin1,PIN_VAL_LOW);
		DIO_voidSetPinVal(Motor_Port,Motor1_Pin2,PIN_VAL_LOW);
		DIO_voidSetPinVal(Motor_Port,Motor2_Pin1,PIN_VAL_HIGH);
		DIO_voidSetPinVal(Motor_Port,Motor2_Pin2,PIN_VAL_LOW);
	}
	//stop
	else if(Copy_u8Direction==MOTOR_Stop)
		{
			DIO_voidSetPinVal(Motor_Port,Motor1_Pin1,PIN_VAL_LOW);
			DIO_voidSetPinVal(Motor_Port,Motor1_Pin2,PIN_VAL_LOW);
			DIO_voidSetPinVal(Motor_Port,Motor2_Pin1,PIN_VAL_LOW);
			DIO_voidSetPinVal(Motor_Port,Motor2_Pin2,PIN_VAL_LOW);
		}
	else
	{
		LocalErrorState=NOK;
	}
	return LocalErrorState;
}

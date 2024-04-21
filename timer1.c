/***********************************************************************/
/***********************************************************************/
/********************Layer :HAL******************************************/
/********************Author: Mohamed Shalpy*****************************************/
/********************Date :10 OCT 2023*********************************/
/********************Ver:01*************************************/
//                              # Timer 1 #
/*******************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "timer1.h"
#include "DIO_interface.h"


static void (*Global_ptrtofunc) (void) = NULL;


void TIMER1_voidInit(void)
{
	// Fast PWM
		/*
		CLR_BIT(TCCR1A,TCCR1A_WGM10);
		SET_BIT(TCCR1A,TCCR1A_WGM11);
		SET_BIT(TCCR1B,TCCR1B_WGM12);
		SET_BIT(TCCR1B,TCCR1B_WGM13);
		 */
		// Normal Mode
		CLR_BIT(TCCR1A,TCCR1A_WGM10);
		CLR_BIT(TCCR1A,TCCR1A_WGM11);
		CLR_BIT(TCCR1B,TCCR1B_WGM12);
		CLR_BIT(TCCR1B,TCCR1B_WGM13);

		/*Enable overflow interrupt*/
		SET_BIT(TIMSK,TIMSK_TOIE1);

		CLR_BIT(TCCR1A,TCCR1A_COM1A0);
		CLR_BIT(TCCR1A,TCCR1A_COM1A1);
		CLR_BIT(TCCR1A,TCCR1A_COM1B0);
		CLR_BIT(TCCR1A,TCCR1A_COM1B1);
		// Pre_Scaler1
		SET_BIT(TCCR1B,TCCR1B_CS10);
		CLR_BIT(TCCR1B,TCCR1B_CS11);
		CLR_BIT(TCCR1B,TCCR1B_CS12);
}
void TIMER1_voidWriteValue(u16 Copy_u16Value)
{
	TCNT1 = Copy_u16Value;
}
u16 TIMER1_u16ReadValue(void)
{
	return TCNT1;
}
void TIMER1_voidSetOCRValue(u16 Copy_u16Value)
{
	OCR1A = Copy_u16Value;
}
void TIMER1_voidSetICRValue(u16 Copy_u16Value)
{
	ICR1A = Copy_u16Value;
}
u8 TIMER1_u8SetCallBack(void (*Copy_ptrtofunc) (void))
{
	u8 Local_u8Errorstate= OK;

		if (Copy_ptrtofunc !=NULL)
		{
			Global_ptrtofunc=Copy_ptrtofunc;
		}

		else
		{
			Local_u8Errorstate = NOK;
		}

		return Local_u8Errorstate;

}
void __vector_9 (void) __attribute__((signal));
void __vector_9 (void)
{
	if (Global_ptrtofunc !=NULL)
	{
		Global_ptrtofunc ();

	}
}

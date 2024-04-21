#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "exti_config.h"
#include "exti_interface.h"
#include "exti_private.h"

void (*Glopalptrtofunc0)(void)=NULL;
void (*Glopalptrtofunc1)(void)=NULL;
void (*Glopalptrtofunc2)(void)=NULL;

void EXTI_voidEnable(INT_num intnumber)
{
	switch(intnumber)
	{
	case int0:SET_BIT(GICR,GICR_INT0);
	break;
	case int1:SET_BIT(GICR,GICR_INT1);
	break;
	case int2:SET_BIT(GICR,GICR_INT2);
	break;

	}
}

void EXTI_voidDisable(INT_num intnumber)
{

	switch(intnumber)
	{
	case int0:CLR_BIT(GICR,GICR_INT0);
	break;
	case int1:CLR_BIT(GICR,GICR_INT1);
	break;
	case int2:CLR_BIT(GICR,GICR_INT2);
	break;
	}
}

void EXTI_voidSetSenseControl(INT_num intnumber,INT_sense SenseControl)
{

	switch(intnumber)
	{
	case int0:
		switch(SenseControl)
		{
		case Low_Level:
			CLR_BIT(MCUCR,MCUCR_ISC00);
			CLR_BIT(MCUCR,MCUCR_ISC01);
			break;
		case On_Change:
			SET_BIT(MCUCR,MCUCR_ISC00);
			CLR_BIT(MCUCR,MCUCR_ISC01);
			break;
		case Falling_edge:
			SET_BIT(MCUCR,MCUCR_ISC01);
			CLR_BIT(MCUCR,MCUCR_ISC00);
			break;
		case Rising_edge:
			SET_BIT(MCUCR,MCUCR_ISC00);
			SET_BIT(MCUCR,MCUCR_ISC01);
			break;
		}
		break;
		case int1:
			switch(SenseControl)
			{
			case Low_Level:
				CLR_BIT(MCUCR,MCUCR_ISC10);
				CLR_BIT(MCUCR,MCUCR_ISC11);
				break;
			case On_Change:
				SET_BIT(MCUCR,MCUCR_ISC10);
				CLR_BIT(MCUCR,MCUCR_ISC11);
				break;
			case Falling_edge:
				SET_BIT(MCUCR,MCUCR_ISC10);
				CLR_BIT(MCUCR,MCUCR_ISC11);
				break;
			case Rising_edge:
				SET_BIT(MCUCR,MCUCR_ISC10);
				SET_BIT(MCUCR,MCUCR_ISC11);
				break;
			}

			break;
			case int2:
				switch(SenseControl)
				{
				case Falling_edge:
					CLR_BIT(MCUCSR,MCUCSR_ISC2);
					break;
				case Rising_edge:
					SET_BIT(MCUCSR,MCUCSR_ISC2);

					break;
				}
				break;
	}
}
u8 EXTI_u8SetCallBack(INT_num intnumber,void (*ptrtofunc)(void))
{
	u8 Local_u8ErorrState=OK;
if(*ptrtofunc!=NULL)
{
	switch(intnumber)
	{
	case int0:
		Glopalptrtofunc0=ptrtofunc;
		break;
	case int1:
			Glopalptrtofunc1=ptrtofunc;
			break;
	case int2:
			Glopalptrtofunc2=ptrtofunc;
			break;
	}
}
else
{
	Local_u8ErorrState=NOK;
}


	return Local_u8ErorrState;
}
void __vector_1(void) __attribute__((signal));

void __vector_1(void)
{
	if(Glopalptrtofunc0!=NULL)
	{
	Glopalptrtofunc0();
	}
	else
	{
		asm("NOP");
	}
}
void __vector_2(void) __attribute__((signal));

void __vector_2(void)
{
	if(Glopalptrtofunc1!=NULL)
	{
	Glopalptrtofunc1();
	}
	else
	{
		asm("NOP");
	}
}
void __vector_3(void) __attribute__((signal));

void __vector_3(void)
{
	if(Glopalptrtofunc2!=NULL)
	{
	Glopalptrtofunc2();
	}
	else
	{
		asm("NOP");
	}
}





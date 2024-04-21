#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "timer1_config.h"
#include "timer1_interface.h"
#include "timer1_private.h"


static void(*GlobalPtrtoFun)(void)=NULL;

void Timer1_voidInit(void)
{
	//configure fast pwm mode 14

	//CONFIGURE prescaler 8
	TCCR1B&=0B11111000;
	TCCR1B|=2;
}
void Timer1_voidSetOCR1Value(u16 Copy_u16Value)
{
	OCR1A=Copy_u16Value;
}
void HWICU_voidInit(void)
{
SET_BIT(TIMSK,TIMSK_TICIE1);
SET_BIT(TCCR1B,TCCR1B_ICES);
}
void HWICU_voidInterruptEnable(void)
{
	SET_BIT(TIMSK,TIMSK_TICIE1);

}
void HWICU_voidInterruptDisable(void)
{
	CLR_BIT(TIMSK,TIMSK_TICIE1);
}
void HWICU_voidSetTriggerEdge(u8 Copy_u8Edge)
{
	if(Copy_u8Edge==RISING_EDGE)
	{
		SET_BIT(TCCR1B,TCCR1B_ICES);
	}
	else if (Copy_u8Edge==FALLING_EDGE) {
		CLR_BIT(TCCR1B,TCCR1B_ICES);

	}
}
void HWICU_voidSetCallBack(void(*ptr)(void))
{
	if(ptr!=NULL)
	{
		GlobalPtrtoFun=ptr;
	}
	else
	{
		asm("nop");
	}

}
u16 HWICU_u16ReadTicks(void)
{
	return ICR1;
}
void __vector_6(void) __attribute__((signal));
void __vector_6(void)
{
	GlobalPtrtoFun();
}



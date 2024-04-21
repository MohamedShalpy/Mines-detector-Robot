#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_



typedef enum
{
	int0=0,
	int1,
	int2
}INT_num;

typedef enum
{
	Low_Level=0,
	On_Change,
	Falling_edge,
	Rising_edge

}INT_sense;



void EXTI_voidEnable(INT_num intnumber);

void EXTI_voidDisable(INT_num intnumber);

void EXTI_voidSetSenseControl(INT_num intnumber,INT_sense SenseControl);
u8 EXTI_u8SetCallBack(INT_num intnumber,void (*ptrtofunc)(void));


#endif

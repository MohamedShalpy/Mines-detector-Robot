/***********************************************************************/
/***********************************************************************/
/********************Layer :HAL******************************************/
/********************Author: Mohamed Shalpy*****************************************/
/********************Date :10 OCT 2023*********************************/
/********************Ver:01*************************************/
//                              # Mine Sensor #
/*******************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "exti_interface.h"
#include "Mine_config.h"
#include "Mine_interface.h"
#include "Mine_private.h"

static u8 Mine_Flag= NO_MINE;
void MineDetection(void);
void Mine_voidInit(void)
{
	EXTI_voidSetSenseControl(Rising_edge,int2);  //enable rising edge
	EXTI_u8SetCallBack(int2,&MineDetection);  //Call Function Mine Detection for to run in the ISR
}

u8 Mine_u8GetReading(void)
{
	return Mine_Flag;
}
void MineDetection(void)
{
	static u8 LocalConter=0;
	TOG_BIT(LocalConter,0);
	if(LocalConter==1)
	{
		Mine_Flag=MINE;
	}
	else
		Mine_Flag=NO_MINE;
}

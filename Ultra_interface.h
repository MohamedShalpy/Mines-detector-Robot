/***********************************************************************/
/***********************************************************************/
/********************Layer :HAL******************************************/
/********************Author: Mohamed Shalpy*****************************************/
/********************Date :10 OCT 2023*********************************/
/********************Ver:01*************************************/
//                              # Ultrasonic Sensor #
/*******************************************************************************/
#ifndef Ultra_INTERFACE_H_
#define Ultra_INTERFACE_H_

#define OBSTACLE		1
#define NO_OBSTACLE		2


void Ultra_voidInit(void);


void Ultra_voidTriggerReading(void);

void Ultra_voidEchoReading(void);

u8 Ultra_u8GetReading(void);



#endif

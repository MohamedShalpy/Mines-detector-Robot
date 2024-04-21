/*
 * Motor1_interface.h
 *
 *  Created on: Jan 24, 2024
 *      Author: Dell5570
 */

#ifndef MOTOR1_INTERFACE_H_
#define MOTOR1_INTERFACE_H_




#define MOTOR_Fwd    	1
#define MOTOR_Back  	2
#define MOTOR_Right   	3
#define MOTOR_Left  	4
#define MOTOR_Stop  	5

void Motor_voidInit(void);
u8 MOTOR_u8DCRot(u8 Copy_u8Direction,u8 Copy_u8Speed);



#endif /* MOTOR1_INTERFACE_H_ */

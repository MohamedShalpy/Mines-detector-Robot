#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "delay.h"
#include "DIO_interface.h"
#include "exti_interface.h"
#include "GIE_interface.h"
#include "timer1.h"
#include "CLCD_interface.h"
#include "Ultra_interface.h"
#include "Mine_interface.h"
#include "Motor1_interface.h"
#include "Buzzer.h"
#include "led.h"

u8 MotorSpeed=255;    //speed of motor
void MotionFwd(void) ;
void MotionBack(void);
void MotionRIGHT(void);
void MotionLEFT(void);
void MotionSTOP(void);

int main()
{

   DIO_voidSetPortDir(D,PORT_DIR_OUT);
	DIO_voidSetPortDir(B,PORT_DIR_OUT);
	DIO_voidSetPortDir(C,PORT_DIR_OUT);
	DIO_voidSetPortDir(A,PORT_DIR_OUT);
	DIO_voidSetPinDir(B,PIN2,PIN_DIR_OUT);
	CLCD_voidInit();
	Buzzer_voidinit();
	Led_voidinit();
	TIMER1_voidInit();
	Ultra_voidInit();
	Mine_voidInit();
	EXTI_voidEnable(int2);
	GIE_voidEnable();
	Motor_voidInit();




	CLCD_voidSendCommand(1);
	CLCD_voidSendPosition(1,1);
	CLCD_voidSendString("Loading...");
	delay_s(3);
	CLCD_voidSendCommand(1);
	CLCD_voidSendPosition(1,1);
	CLCD_voidSendString("Let's Go ^-^");
	delay_s(5);
	while(1)
	{
		u8 LocalObs = Ultra_u8GetReading(); // Variable to receive UltraSonic Reading
		u8 LocalMin= Mine_u8GetReading();  // Variable to receive Mine Detector Reading
		/*
		 * Check if there is No Obstacles
		 * if there is Mine Motor Stop, Buzzer Turn On and Red Led will be active
		 * If there is no mine Motor Move Forward Buzzer Turn Off and Green Led will be active
		 */
		if(LocalObs == NO_OBSTACLE)
		{
			if(LocalMin==MINE)
			{
				MotionSTOP();
				Buzzer_voidEnable();
				Led_voidLedGreenDisable();
				Led_voidLedYellowDisable();
				Led_voidLedRedEnable();

				CLCD_voidSendCommand(1);
				CLCD_voidSendPosition(1,1);
				CLCD_voidSendString("Mine Detect");
				delay_s(2);
				CLCD_voidSendCommand(1);
				CLCD_voidSendPosition(1,1);
				CLCD_voidSendString("Car Stop");
				delay_s(5);
			}
			else if(LocalMin==NO_MINE)
			{
				MotionBack();
				Buzzer_voidDisable();
				Led_voidLedGreenEnable();
				Led_voidLedYellowDisable();
				Led_voidLedRedDisable();

				CLCD_voidSendCommand(1);
				CLCD_voidSendPosition(1,1);
				CLCD_voidSendString("No Obstacle");
				delay_s(2);
				CLCD_voidSendCommand(1);
				CLCD_voidSendPosition(1,1);
				CLCD_voidSendString("Car Move");
				delay_s(5);
			}
		}
		/*
		 * Check if there is Obstacles
		 * if there is Mine Motor Stop, Buzzer Turn On and Red Led will be active
		 * If there is no mine Motor Move Left,  Buzzer Turn Off and Yellow Led will be active
		 */
		if(LocalObs==OBSTACLE)
		{
			if(LocalMin==MINE)
			{
				MotionSTOP();
				Buzzer_voidEnable();
				Led_voidLedGreenDisable();
				Led_voidLedYellowDisable();
				Led_voidLedRedEnable();

				CLCD_voidSendCommand(1);
				CLCD_voidSendPosition(1,1);
				CLCD_voidSendString("Mine Detect");
				delay_s(2);
				CLCD_voidSendCommand(1);
				CLCD_voidSendPosition(1,1);
				CLCD_voidSendString("Car Stop");
				delay_s(5);
			}
			else if(LocalMin==NO_MINE)
			{
				MotionLEFT();
				Buzzer_voidDisable();
				Led_voidLedGreenDisable();
				Led_voidLedYellowEnable();
				Led_voidLedRedDisable();

				CLCD_voidSendCommand(1);
				CLCD_voidSendPosition(1,1);
				CLCD_voidSendString("Obstacle Detect");
				delay_s(2);
				CLCD_voidSendCommand(1);
				CLCD_voidSendPosition(1,1);
				CLCD_voidSendString("Move Left");
				delay_s(5);
			}
		}
		else
		{
			//nothing
		}

	}
	return 0;

}
void MotionFwd(void)
{
	// Motion Forward
	MOTOR_u8DCRot(MOTOR_Fwd,MotorSpeed);
}
void MotionBack(void)
{
	// Motion BACK
	MOTOR_u8DCRot(MOTOR_Back,MotorSpeed);
}
void MotionRIGHT(void)
{
	// Motion right
	MOTOR_u8DCRot(MOTOR_Right,MotorSpeed);
}
void MotionLEFT(void)
{
	// Motion left
	MOTOR_u8DCRot(MOTOR_Left,MotorSpeed);
}
void MotionSTOP(void)
{
	// Motion stop
	MOTOR_u8DCRot(MOTOR_Stop,MotorSpeed);
}

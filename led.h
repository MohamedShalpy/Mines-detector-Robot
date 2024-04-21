/***********************************************************************/
/***********************************************************************/
/********************Layer :HAL******************************************/
/********************Author: Mohamed Shalpy*****************************************/
/********************Date :10 OCT 2023*********************************/
/********************Ver:01*************************************/
//                              # Led #
/*******************************************************************************/

#ifndef Led_H_
#define Led_H_

/*
 * Options
 * 1- PORTA
 * 2- PORTB
 * 3- PORTC
 * 4- PORTD
 */

#define Led_Port      C


/*
 * Options
 * 1- PIN0
 * 2- PIN1
 * 3- PIN2
 * 4- PIN3
 * 5- PIN4
 * 6- PIN5
 * 7- PIN6
 * 8- PIN7
 */

#define Led_Red_Pin       5   // Mine Detect Led
#define Led_Yellow_Pin    6   // Obstacle Detect
#define Led_Green_Pin     7   // All Clear


void Led_voidinit(void);

void Led_voidLedRedEnable(void);
void Led_voidLedGreenEnable(void);
void Led_voidLedYellowEnable(void);

void Led_voidLedRedDisable(void);
void Led_voidLedGreenDisable(void);
void Led_voidLedYellowDisable(void);


#endif

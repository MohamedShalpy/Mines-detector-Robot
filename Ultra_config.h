/***********************************************************************/
/***********************************************************************/
/********************Layer :HAL******************************************/
/********************Author: Mohamed Shalpy*****************************************/
/********************Date :10 OCT 2023*********************************/
/********************Ver:01*************************************/
//                              # Ultrasonic Sensor #
/*******************************************************************************/
#ifndef Ultra_CONFIG_H_
#define Ultra_CONFIG_H_

/*Check every 0.5ms       (500us/(256*0.125us)) */
#define CheckTime 	    16


/*Minimum distance between obstacle in cm*/
#define MinDistance		30

/*
 * Options
 * 1- PORT A
 * 2- PORT B
 * 3- PORT C
 * 4- PORT D
 */

#define Trigger_Port  D
#define Echo_Port     D

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

#define   TRIGGER_Pin   5
#define   ECHO_Pin      6



#endif

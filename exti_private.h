#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

/*
 * OBJECTIVE :
 * SET SENSE CONTROL FOR INT0,INT1
 */
#define MCUCR    *((volatile u8 *)0x55)
#define MCUCR_ISC00      0
#define MCUCR_ISC01      1
#define MCUCR_ISC10      2
#define MCUCR_ISC11      3

/*
 * OBJECTIVE :
 * SET SENSE CONTROL FOR INT2
 */
#define MCUCSR   *((volatile u8 *)0x54)
#define MCUCSR_ISC2      6


/*
 * OBJECTIVE :
 * SPACIFIC ENABLE FOR INT0,INT1,INT2
 */
#define GICR     *((volatile u8 *)0x5B)
#define GICR_INT1   7
#define GICR_INT0   6
#define GICR_INT2   5






#endif

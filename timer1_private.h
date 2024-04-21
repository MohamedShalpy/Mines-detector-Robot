#ifndef TIMER1_PRIVATE_H_
#define TIMER1_PRIVATE_H_





#define  TCCR1A  *((volatile u8*)0X4F)
#define TCCR1A_COM1A1       7
#define TCCR1A_COM1A0       6
#define TCCR1A_COM1B1       5
#define TCCR1A_COM1B0       4
#define TCCR1A_WGM11        1
#define TCCR1A_WGM10        0





#define TCCR1B   *((volatile u8*)0X4E)
#define TCCR1B_ICN1        7
#define TCCR1B_ICES        6
#define TCCR1B_WGM13       4
#define TCCR1B_WGM12       3




#define TCNT1      *((volatile u16*)0X4C)

#define ICR1       *((volatile u16*)0X46)
#define OCR1A      *((volatile u16*)0X4A)
#define TIMSK      *((volatile u16*)0X59)
#define TIMSK_TICIE1      5
#endif

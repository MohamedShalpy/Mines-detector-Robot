#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_


void Timer1_voidInit(void);
void Timer1_voidSetOCR1Value(u16 Copy_u16Value);

u16 HWICU_u16ReadTicks(void);
void HWICU_voidSetTriggerEdge(u8 Copy_u8Edge);
void HWICU_voidInterruptDisable(void);
void HWICU_voidSetCallBack(void(*ptr)(void));
void HWICU_voidInit(void);
void HWICU_voidInterruptEnable(void);
#define FALLING_EDGE   1
#define RISING_EDGE    1




#endif

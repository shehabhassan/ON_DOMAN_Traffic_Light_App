/*
 * TIMER.h
 * Created: 2/18/2023 9:52:04 PM
 *  Author: shehab mohamed shawki
 */ 
#ifndef TIMER_H_
#define TIMER_H_
#include "../../UTILITES/BIT_FUN.h"
#include "../../UTILITES/Registers.h"
#include "../../UTILITES/Types_def.h"
#define F_CPU 8000000 //8MHZ
#include <util/delay.h>
/************************************************************************/
/* Timer MODE OF TIMER0- REG                                            */
/************************************************************************/
typedef enum
{
	MODE_NORMAL,
	MODE_PHASE_CORRECT,
	MODE_CTC,
	MODE_FAST_PWM
}Timer_Mode;
/************************************************************************/
/*  PRESCALER FOR TIMER0 - REG -                                        */
/************************************************************************/
typedef enum{
	NO_PRESCALER,
	PRESCALER_8,
	PRESCALER_64,
	PRESCALER_256,
	PRESCALER_1024,
}Timer_Preccaler;
/************************************************************************/
/*    Configuration of pins  - TCCR0                                    */
/************************************************************************/
#define CS00    0
#define CS01    1
#define CS02    2
#define WGM01   3
#define COM00   4
#define COM01   5
#define WGM00   6
#define FOC0    7
/************************************************************************/
/*  Configuration of  Register Timer 0 -  TIFR                          */
/************************************************************************/
#define TOV0 0
#define OCF0 1
/************************************************************************/
/*Configuration of  Register Timer 0 - TIMSK                            */
/************************************************************************/
#define TOIE0   0
#define OCIE0   1
#define TOIE1   2
#define OCIE1B  3
#define OCIE1A  4
#define TICIE1  5
#define TOIE2   6
#define OCIE2   7
/* Timer/Counter0 Compare Match */
#define TIMER0_OC_vect		__vector_10
/* Timer/Counter0 Overflow */
#define TIMER0_OVF_vect	    __vector_11
/************************************************************************/
/* error return enum                                                    */
/************************************************************************/
typedef enum
{
	TIMER_OK,
	TIMER_ERROR
}TIMER_Error_t;
/************************************************************************/
/* FUNCTION Of Timer                                                    */
/************************************************************************/
TIMER_Error_t TIMER0_MODE_INIT(Timer_Mode MODE,uint8_t ini_value);// SET MODE  TIMER0 
TIMER_Error_t TIMERO_PRESCALER_INIT(Timer_Preccaler prescaler);// SET Prescaler
TIMER_Error_t TIMER0_OV_Interrupt_Enable(void); // ENABLE INTRRUPT 
TIMER_Error_t TIMER0_Clear_ovf_Flag(void);//ENABLE over flow flag
TIMER_Error_t TIMER0_STOP(void);
TIMER_Error_t TIMER0_OV_Interrupt_Disable(void);//DISABLE INTRRUPT
TIMER_Error_t TIMER0_OV_SETCALLBACK(void(*local_f_ptr)(void));//CALLBACK FUNCTION 
#endif /* TIMER_H_ */
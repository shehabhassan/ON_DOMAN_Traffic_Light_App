/*
 * Ex_Intrrupt.h
 *
 * Created: 2/18/2023 9:53:13 PM
 *  Author: shehab mmohamed shawki 
 */ 

#ifndef EX_INTRRUPT_H_
#define EX_INTRRUPT_H_
#include "../../UTILITES/BIT_FUN.h"
#include "../../UTILITES/Registers.h"
#include "../../UTILITES/Types_def.h"
#define F_CPU 8000000 //8MHZ
#include <util/delay.h>
/************************************************************************/
/*           TRIGGER EDGE FOR EXTERNAL INTRRUPT INT0                    */
/************************************************************************/
typedef enum{
	LOW_LEVEL,
	ANY_LOGIC_CHANGE,
	FALLING_EDGE,
	RISING_EDGE,
}Tri_Edge;
#define  TRUE 1
/************************************************************************/
/*    control register                                                  */
/************************************************************************/
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3
#define ISC2  6   //control and statues register
/************************************************************************/
/*      general interrupt control register                              */
/************************************************************************/
#define INT2 5
#define INT0 6
#define INT1 7
/************************************************************************/
/*      general interrupt Flag register                                 */
/************************************************************************/
#define INTF1 7
#define INTF0 6
#define INTF2 5
/************************************************************************/
/*                          Interrupt vectors                           */
/************************************************************************/
/* External Interrupt Request 0 */
#define INT0_vect			__vector_1
/* External Interrupt Request 1 */
#define INT1_vect			__vector_2
/* External Interrupt Request 2 */
#define INT2_vect			__vector_3
/************************************************************************/
/* interrupt functions                                                  */
/************************************************************************/
# define sei()  __asm__ __volatile__ ("sei" ::) // interrupt assembly for enable SREG
# define cli()  __asm__ __volatile__ ("cli" ::) // interrupt assembly for STOP SREG
/************************************************************************/
/*       ISR                                                            */
/************************************************************************/
#define ISR(vector,...)            \
void vector (void) __attribute__ ((signal))__VA_ARGS__ ; \
void vector (void)
/************************************************************************/
typedef enum{
	INTER_OK,
	INTER_ERROR
}INTERRUPTS_ERROR_t;
/************************************************************************/
/* FUNCTION FOR INTRRUPT                                                */
/************************************************************************/
INTERRUPTS_ERROR_t EXternal_INT0_Enable(void);//enable external  INT0 interrupt
INTERRUPTS_ERROR_t EXternal_INT0_Disable(void);//disable external INT0 interrupt
INTERRUPTS_ERROR_t EXternal_INT0_Trigger_Edge(Tri_Edge Edge);////trigger edge for  external interrupt INT0
INTERRUPTS_ERROR_t EXternal_INT0_SetCallBack(void(*LocalPtr)(void));//call back  function for external interrupt INT0
#endif /* EX_INTRRUPT_H_ */
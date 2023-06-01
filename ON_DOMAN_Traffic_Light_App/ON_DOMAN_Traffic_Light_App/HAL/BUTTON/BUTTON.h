/*
 * BUTTON.h
 *
 * Created: 2/19/2023 12:53:04 AM
 *  Author: shehab mohamed shawki
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_
#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/TIMER/TIMER.h"
#include "../../MCAL/EX_Intrrupt/Ex_Intrrupt.h"
/************************************************************************/
/* Macros OF BUTTONS                                                    */
/************************************************************************/
#define  BUTTON_INT_PORTD  PORT_D
#define  BUTTON_INT_PIND2  PIN2
/************************************************************************/
typedef enum
{
	BUTTON_OK,
	BUTTON_ERROR
}BUTTON_Error_t;
/************************************************************************/
/*  MAIN FUNCTION                                                       */
/************************************************************************/
BUTTON_Error_t BUTTON_INIT(uint8_t PORT_BUTTON,uint8_t PIN_BUTTON);
BUTTON_Error_t BUTTON_READ(uint8_t PORT_BUTTON,uint8_t PIN_BUTTON,uint8_t *value);
BUTTON_Error_t BUTTON_interrupt();

#endif /* BUTTON_H_ */
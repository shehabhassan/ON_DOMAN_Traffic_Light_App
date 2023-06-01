/*
 * EX_Intrrupt.c
 *
 * Created: 2/18/2023 9:52:46 PM
 *  Author: shehab mohamd shawki
 */ 
#include "Ex_Intrrupt.h"
void (*INT0_FLAG_PTR)(void)=NULL_PTR;
/************************************************************************/
/*  INTERRPT 0 ENABLE                                                   */
/************************************************************************/
INTERRUPTS_ERROR_t EXternal_INT0_Enable(void)
{
	INTERRUPTS_ERROR_t EXternal_INT0_EN_error = INTER_OK;
	SET(GICR,INT0);
	if (TRUE)
	{
      EXternal_INT0_EN_error = INTER_OK;		
	}
	return EXternal_INT0_EN_error;

}
/************************************************************************/
/*  Interrupt 0 Disable                                                 */
/************************************************************************/
INTERRUPTS_ERROR_t EXternal_INT0_Disable(void)
{
	INTERRUPTS_ERROR_t EXternal_INT0_Dis_error = INTER_OK;
	CLEAR(GICR,INT0);
	if (TRUE)
	{
		EXternal_INT0_Dis_error= INTER_OK;
	}
	return EXternal_INT0_Dis_error;
}
/************************************************************************/
/* Interrupt trigger edge                                                */
/************************************************************************/
INTERRUPTS_ERROR_t EXternal_INT0_Trigger_Edge(Tri_Edge Edge)
{
	INTERRUPTS_ERROR_t EXternal_INT0_Trig_error = INTER_OK;
	switch(Edge)
	{
		case LOW_LEVEL:
		CLEAR(MCUCR, ISC00);
		CLEAR(MCUCR, ISC01);
		if (TRUE)
		{
			EXternal_INT0_Trig_error = INTER_OK;
		}
		break;
		case ANY_LOGIC_CHANGE:
		SET(MCUCR, ISC00);
		CLEAR(MCUCR, ISC01);
		if (TRUE)
		{
			EXternal_INT0_Trig_error = INTER_OK;
		}
		break;
		case FALLING_EDGE:
		CLEAR(MCUCR, ISC00);
		SET(MCUCR, ISC01);
		if (TRUE)
		{
			EXternal_INT0_Trig_error = INTER_OK;
		}
		break;
		case RISING_EDGE:
		SET(MCUCR, ISC00);
		SET(MCUCR, ISC01);
		if (TRUE)
		{
			EXternal_INT0_Trig_error = INTER_OK;
		}
		break;
	}
return EXternal_INT0_Trig_error;
}

/************************************************************************/
/*                  callback function interrupt external                */
/************************************************************************/
INTERRUPTS_ERROR_t EXternal_INT0_SetCallBack(void(*LocalPtr)(void))
{
	INTERRUPTS_ERROR_t EXternal_INT0_call_error = INTER_OK;
	LocalPtr=INT0_FLAG_PTR;
	if (TRUE)
	{
		EXternal_INT0_call_error = INTER_OK;
	}
	return EXternal_INT0_call_error;
}
/************************************************************************/
/*  ISR for interrupt function                                          */
/************************************************************************/
ISR(INT0_vect)
{
	if(NULL_PTR!=INT0_FLAG_PTR)
	{
		INT0_FLAG_PTR();
	}
}


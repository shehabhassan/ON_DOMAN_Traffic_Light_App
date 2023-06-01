/*
 * TIMER.c
 *
 * Created: 2/18/2023 9:52:17 PM
 *  Author: shehab mohamed shawki
 */ 
#include "TIMER.h"
/*************************Pointer to functions to be assigned to ISR****************************/
void (*Timer0_OVF_Flag) (void)=NULL_PTR;
/************************************************************************/
/* FUNCTION Of Timer                                                    */
/************************************************************************/
TIMER_Error_t TIMER0_MODE_INIT(Timer_Mode MODE,uint8_t ini_value)  //SET MODE OF TIMER0
{
	TIMER_Error_t timer_ini_error=TIMER_OK;
	switch(MODE)
	{
		case MODE_NORMAL:
		CLEAR(TCCR0,WGM00);
		CLEAR(TCCR0,WGM01);
		if (1)
		{
		  timer_ini_error=TIMER_OK;
		}
		break;
		case MODE_PHASE_CORRECT:
		SET(TCCR0,WGM00);
		CLEAR(TCCR0,WGM01);
		if (1)
		{
			timer_ini_error=TIMER_OK;
		}
		break;
		case MODE_CTC:
		CLEAR(TCCR0,WGM00);
		SET(TCCR0,WGM01);
		if (1)
		{
			timer_ini_error=TIMER_OK;
		}
		break;
		case MODE_FAST_PWM:
		SET(TCCR0,WGM00);
		SET(TCCR0,WGM01);
		if (1)
		{
			timer_ini_error=TIMER_OK;
		}
		break;
	}
	TCNT0 = ini_value;
return timer_ini_error;
}
/************************************************************************/
/* stop TIMER0                                                          */
/************************************************************************/
TIMER_Error_t TIMER0_STOP(void)
{
	TIMER_Error_t timer_stop_error=TIMER_OK;
	TCCR0 = 0x00;
	if (1)
	{
		timer_stop_error=TIMER_OK;
	}
	return timer_stop_error;
}
/************************************************************************/
/* TIMER0 Configuration of prescaler                                    */
/************************************************************************/
TIMER_Error_t TIMERO_PRESCALER_INIT(Timer_Preccaler prescaler){

TIMER_Error_t 	timer_pre_error = TIMER_OK;
switch (prescaler)
{
case NO_PRESCALER:
    SET(TCCR0,CS00);
	CLEAR(TCCR0,CS01);
	CLEAR(TCCR0,CS02);
	if (1)
	{
		timer_pre_error = TIMER_OK;
	}
	break;
	case PRESCALER_8:
	CLEAR(TCCR0,CS00);
	SET(TCCR0,CS01);
	CLEAR(TCCR0,CS02);
	if (1)
	{
		timer_pre_error = TIMER_OK;
	}
	break;
	case PRESCALER_64:
	SET(TCCR0,CS00);
	SET(TCCR0,CS01);
	CLEAR(TCCR0,CS02);
	if (1)
	{
		timer_pre_error = TIMER_OK;
	}
	break;
   case PRESCALER_256:
   CLEAR(TCCR0,CS00);
   CLEAR(TCCR0,CS01);
   SET(TCCR0,CS02);
	if (1)
	{
		timer_pre_error = TIMER_OK;
	}
	break;
   case PRESCALER_1024:
   SET(TCCR0,CS00);
   CLEAR(TCCR0,CS01);
   SET(TCCR0,CS02);
    if (1)
    {
	    timer_pre_error = TIMER_OK;
    } 
	  break;
}
return timer_pre_error ;

}
/************************************************************************/
/* OVER FLOW ENABLE                                                     */
/************************************************************************/

TIMER_Error_t TIMER0_OV_Interrupt_Enable(void) // ENABLE INTRRUPT
{   
	TIMER_Error_t  timer_ovr_error = TIMER_OK;
	SET(TIMSK,TOIE0);
	if (1)
	{
		timer_ovr_error = TIMER_OK;
	}
	return timer_ovr_error ;
}
/************************************************************************/
/*      OVER FLOW Flag clear                                            */
/************************************************************************/
TIMER_Error_t TIMER0_Clear_ovf_Flag(void)
{
	TIMER_Error_t timer_clear_error=TIMER_OK;
	SET(TIFR,TOV0);
	if (1)
	{
		timer_clear_error = TIMER_OK;
	}
	return timer_clear_error ;
}
/************************************************************************/
/* TIMER0 CALLBACK FUNCTION FOR OVERFLOW                                */
/************************************************************************/
TIMER_Error_t TIMER0_OV_SETCALLBACK(void(*flag_ptr)(void))//CALLBACK FUNCTION
{
	TIMER_Error_t timer_oc_call_error=TIMER_OK;
	flag_ptr=Timer0_OVF_Flag;
	if (1)
	{
		timer_oc_call_error=TIMER_OK;
	}
	return timer_oc_call_error;
}
/************************************************************************/
/*     Timer 0 ISR overflow function                                    */
/************************************************************************/
ISR(TIMER0_OVF_vect)
{
	if(NULL_PTR!= Timer0_OVF_Flag)
	{
		Timer0_OVF_Flag();
	}
}

/*
 * BUTTON.c
 *
 * Created: 2/19/2023 12:52:23 AM
 *  Author: shehab mohamed shawki
 */ 
#include "BUTTON.h"
/************************************************************************/
/*  MAIN FUNCTION                                                       */
/************************************************************************/
BUTTON_Error_t BUTTON_INIT(uint8_t PORT_BUTTON,uint8_t PIN_BUTTON){
	BUTTON_Error_t button_init_error=BUTTON_OK;
	DIO_Init(INPUT,PORT_BUTTON,PIN_BUTTON);
	if (1)
	{
	  button_init_error=BUTTON_OK;
	}
	return button_init_error;
}
BUTTON_Error_t BUTTON_READ(uint8_t PORT_BUTTON,uint8_t PIN_BUTTON,uint8_t *value){
	BUTTON_Error_t button_read_error=BUTTON_OK;
	DIO_Read(value,PORT_BUTTON,PIN_BUTTON);
 if (1)
 {
	button_read_error=BUTTON_OK;
 }
return  button_read_error;
}
BUTTON_Error_t BUTTON_interrupt()
{
		EXternal_INT0_Trigger_Edge(FALLING_EDGE);
		BUTTON_INIT(BUTTON_INT_PORTD, BUTTON_INT_PIND2);
}

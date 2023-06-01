/*
 * DIO.c
 *
 * Created: 2/18/2023 7:15:11 PM
 *  Author: shehab Mohamed shawki 
 */ 

/************************************************************************/
/* Header File .h                                                       */
/************************************************************************/
#include "DIO.h"
/************************************************************************/
/* Global Variables                                                     */
/************************************************************************/
DIO_Error_t DIO_Init(DIO_PinStatus Direction, uint8_t portNumber , DIO_Pin_number PinNumber){
  DIO_Error_t DIO_init_Error = DIO_OK;
  switch (portNumber){
	  case PORT_A:
	  if (Direction==INPUT) 
	  {
		CLEAR(DDRA,PinNumber);  // INPIUT == 0 
	  } 
	  else if(Direction==OUTPUT)
	  {
		SET(DDRA,PinNumber);  //  OUTPUT  == 1 
      } if (TRUE)
      {
	  DIO_init_Error = DIO_OK;
      }
	   break; 
   case PORT_B:
   if(Direction == INPUT){
	   CLEAR(DDRB,PinNumber);   // input == 0
   }else if (Direction == OUTPUT)
   {
	   SET(DDRB,PinNumber);	 // output == 1
   }if (TRUE)
   {
	   DIO_init_Error = DIO_OK;
   }
   break;
   case PORT_C:
   if(Direction == INPUT){
	   CLEAR(DDRC,PinNumber);  // input == 0
   }else if (Direction == OUTPUT)
   {
	   SET(DDRC,PinNumber); // output == 1
   }if (TRUE)
   {
	   DIO_init_Error = DIO_OK;
   }
   break;
   case PORT_D:
   if(Direction == INPUT){
	   CLEAR(DDRD,PinNumber); // input == 0
   }else if (Direction == OUTPUT)
   {
	   SET(DDRD,PinNumber); // output == 1
   }if (TRUE)
   {
	   DIO_init_Error = DIO_OK;
   }
   break;
  }
if (TRUE)
{
	DIO_init_Error = DIO_OK;
}
	return DIO_init_Error;
}
DIO_Error_t DIO_Write(DIO_PinValue value,uint8_t portNumber , DIO_Pin_number PinNumber){
	 DIO_Error_t DIO_write_Error = DIO_OK;
	switch (portNumber){
		case PORT_A:
		if(value == LOW){
			CLEAR(PORTA,PinNumber);  // WRITE == 0
		}else if (value == HIGH)
		{
			SET(PORTA,PinNumber);    // WRITE == 1
	}if (TRUE)
	{
		DIO_write_Error = DIO_OK;
	}
		break;
		case PORT_B:
		if(value == LOW){
			CLEAR(PORTB,PinNumber);  // WRITE == 0
		}else if (value == HIGH)
		{
			SET(PORTB,PinNumber);	// WRITE == 1
	    }if (TRUE)
	   {
		DIO_write_Error = DIO_OK;
	   }
		break;
		case PORT_C:
		if(value == LOW){
			CLEAR(PORTC,PinNumber);  // WRITE == 0
		}else if (value == HIGH)
		{
			SET(PORTC,PinNumber);   // WRITE == 1
		}
		if (TRUE)
		{
			DIO_write_Error = DIO_OK;
		}
		break;
		case PORT_D:
		if(value == LOW){
			CLEAR(PORTD,PinNumber); // WRITE == 0
		}else if (value == HIGH)
		{
			SET(PORTD,PinNumber);  // WRITE == 1
		}if (TRUE)
		{
			DIO_write_Error = DIO_OK;
		}
		break;
	}
	return DIO_write_Error;
}
DIO_Error_t DIO_Read(uint8_t *value,uint8_t portNumber , DIO_Pin_number PinNumber){
	 DIO_Error_t DIO_read_Error = DIO_OK;
	switch (portNumber){
		case PORT_A:
		  *value = READ(PINA,PinNumber); 
		if (TRUE)
		{
			DIO_read_Error = DIO_OK;
		}
		break;
		case PORT_B:
		  *value = READ(PINB,PinNumber);
		 if (TRUE)
		 {
			 DIO_read_Error = DIO_OK;
		 } 
		break;
		case PORT_C:
		  *value = READ(PINC,PinNumber);
		if (TRUE)
		{
			DIO_read_Error = DIO_OK;
		}
		break;
		case PORT_D:
		  *value = READ(PIND,PinNumber);
		if (TRUE)
		{
			DIO_read_Error = DIO_OK;
		}
		break;
		}
       return DIO_read_Error;
}
DIO_Error_t DIO_TOGGLE(uint8_t portNumber , DIO_Pin_number PinNumber){
	DIO_Error_t DIO_toggle_Error = DIO_OK;
	switch (portNumber){
		case PORT_A:
		  TOGGLE(PORTA,PinNumber);  
		if (TRUE)
		{
			DIO_toggle_Error = DIO_OK;
		}
		break;
		case PORT_B:
		  TOGGLE(PORTB,PinNumber);  
		if (TRUE)
		{
			DIO_toggle_Error = DIO_OK;
		}  
		break;
		case PORT_C:
		  TOGGLE(PORTC,PinNumber);  
		if (TRUE)
		{
			DIO_toggle_Error = DIO_OK;
		}
		break;
		case PORT_D:
		  TOGGLE(PORTD,PinNumber);  
		if (TRUE)
		{
			DIO_toggle_Error = DIO_OK;
		}
		break;
	}
	return DIO_toggle_Error;
}

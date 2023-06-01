/*
 * DIO.h
 *
 * Created: 2/18/2023 7:15:28 PM
 *  Author: shehab mohamed shawki
 */ 
#ifndef DIO_H_
#define DIO_H_
#include "../../UTILITES/BIT_FUN.h"
#include "../../UTILITES/REGISTERS.h"
#include "../../UTILITES/Types_def.h"
#define F_CPU 8000000 //8MHZ
#include <util/delay.h>
/************************************************************************/
/*  Internal deriver Typedef                                            */
/************************************************************************/
typedef unsigned char uint8_t;
/************************************************************************/
/* drivers Macros                                                       */
/************************************************************************/
//PORT Defintion. 
#define  PORT_A  'A'
#define  PORT_B  'B'
#define  PORT_C  'C'
#define  PORT_D  'D'
//
#define  TRUE     1
// PIN NUMBERS 
typedef enum {
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7
}DIO_Pin_number;
// Enum  directions
typedef enum {
	INPUT,
	OUTPUT
}DIO_PinStatus;
// Enum  statue value
typedef enum {
  LOW,
  HIGH
}DIO_PinValue;
/************************************************************************/
typedef enum{
	DIO_OK,
	DIO_ERROR
}DIO_Error_t;
/************************************************************************/
/*driver function prototypes                                            */
/************************************************************************/
DIO_Error_t DIO_Init(DIO_PinStatus Direction,uint8_t portNumber , DIO_Pin_number PinNumber);
DIO_Error_t DIO_Write(DIO_PinValue value,uint8_t portNumber , DIO_Pin_number PinNumber);
DIO_Error_t DIO_Read(uint8_t *value,uint8_t portNumber , DIO_Pin_number PinNumber);
DIO_Error_t DIO_TOGGLE(uint8_t portNumber , DIO_Pin_number PinNumber);
#endif /* DIO_H_ */
/*
 * App.h
 *
 * Created: 2/18/2023 10:09:02 PM
 *  Author: sheha
 */ 


#ifndef APP_H_
#define APP_H_
#include "../HAL/LED/LED.h"
#include "../HAL/BUTTON/BUTTON.h"
/************************************************************************/
/* MAIN Function for application                                        */
/************************************************************************/
void APP_INIT(void);
void APP_START(void);
/************************************************************************/
/* Function Helper for application                                      */
/************************************************************************/
void Timer_OVERFLOW(void);
void EXTERNAL_INTRUPPT(void);
#endif /* APP_H_ */
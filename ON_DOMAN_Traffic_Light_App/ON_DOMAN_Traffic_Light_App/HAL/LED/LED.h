/*
 * LED.h
 *
 * Created: 2/18/2023 7:15:52 PM
 *  Author: shehab mohamed shawki
 */ 

#ifndef LED_H_
#define LED_H_
#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/TIMER/TIMER.h"
#include "../../MCAL/EX_Intrrupt/Ex_Intrrupt.h"
typedef enum
{
	LED_OK,
	LED_ERROR
}LED_Error;
/************************************************************************/
/* Function Driver Of LED                                               */
/************************************************************************/
LED_Error LED_Init(uint8_t port_led,uint8_t pin_led);
LED_Error LED_ON(uint8_t port_led,uint8_t pin_led);
LED_Error LED_OFF(uint8_t port_led,uint8_t pin_led);
LED_Error LED_TOGGLE(uint8_t port_led,uint8_t pin_led);
/************************************************************************/
/* DELAY LED FUNC                                                       */
/************************************************************************/
LED_Error LED_blink_mode(uint8_t port_led, uint8_t pin_led,uint8_t mode);
LED_Error LED_NORMAL_DELAY(void);
LED_Error LED_YELLOW_BOTH(void);
unsigned char  DELAY_FLAG;
/************************************************************************/
/* Macros OF LED                                                        */
/************************************************************************/

//CAR LEDS PINS
#define  LED_CAR_RED_PORTA           PORT_A
#define  LED_CAR_YELLOW_PORTA        PORT_A
#define  LED_CAR_GREEN_PORTA         PORT_A
//PEDSTRAIN LEDS PINS
#define  LED_PEDSTRAIN_RED_PORTB     PORT_B
#define  LED_PEDSTRAIN_YELLOW_PORTB  PORT_B
#define  LED_PEDSTRAIN_GREEN_PORTB   PORT_B
//CAR LEDS PINS
#define  LED_CAR_RED_PIN             PIN0
#define  LED_CAR_YELLOW_PIN          PIN1 
#define  LED_CAR_GREEN_PIN           PIN2 
//PEDSTRAIN LEDS PINS
#define  LED_PEDSTRAIN_RED_PIN       PIN0
#define  LED_PEDSTRAIN_YELLOW_PIN    PIN1
#define  LED_PEDSTRAIN_GREEN_PIN     PIN2

#define  CAR_MODE           1
#define  PEDASTRAIN_MODE    2
#define  o_v_f              0

#endif /* LED_H_ */
/*
 * LED.c
 *
 * Created: 2/18/2023 7:16:04 PM
 *  Author: shehab mohamed shawki 
 */ 
#include "LED.h"
LED_Error LED_Init(uint8_t port_led,DIO_Pin_number pin_led){
LED_Error led_init_error=LED_OK;
DIO_Init(OUTPUT,port_led,pin_led);
if (1)
{
	led_init_error=LED_OK;
}
return led_init_error;
}
LED_Error LED_ON(uint8_t port_led,DIO_Pin_number pin_led){
	LED_Error led_on_error=LED_OK;
	DIO_Write(HIGH,port_led,pin_led);
	if (1)
	{
		led_on_error=LED_OK;
	}
 return  led_on_error;
}
LED_Error LED_OFF(uint8_t port_led,uint8_t pin_led){
	LED_Error led_off_error=LED_OK;
	DIO_Write(LOW,port_led,pin_led);
   if (1)
   {
	  led_off_error=LED_OK;
   }
return  led_off_error;
}
LED_Error LED_TOGGLE(uint8_t port_led,uint8_t pin_led){
	
	LED_Error led_toggle_error=LED_OK;
DIO_TOGGLE(port_led,pin_led);
if (1)
{
	led_toggle_error=LED_OK;
}
return led_toggle_error;
}
LED_Error LED_blink_mode(uint8_t port_led, uint8_t pin_led,uint8_t mode){
	LED_Error led_blink_error=LED_OK;
	switch(mode){
		case CAR_MODE:
		// blink yellow led of pedestrian led
		for (int i=0;i<10;i++)
		{
			LED_TOGGLE(LED_CAR_YELLOW_PORTA,LED_CAR_YELLOW_PIN);
			_delay_ms(100);
		}
		if (1)
		{
			led_blink_error=LED_OK;
		}
		break;
		case PEDASTRAIN_MODE:
		// blink yellow led of pedestrian led
		for (int i=0;i<10;i++)
		{
			LED_TOGGLE(LED_PEDSTRAIN_YELLOW_PORTB,LED_PEDSTRAIN_YELLOW_PIN);
			_delay_ms(100);
		}
		if (1)
		{
			led_blink_error=LED_OK;
		}
		break;
	}
	return LED_OK;
}
LED_Error LED_NORMAL_DELAY(void)
{ 
	LED_Error led_normal_error=LED_OK;
	TIMER0_MODE_INIT(MODE_NORMAL,4000);
	TIMERO_PRESCALER_INIT(PRESCALER_1024);
	TIMER0_OV_Interrupt_Enable();
	while(DELAY_FLAG != HIGH);
	DELAY_FLAG = LOW;
	TIMER0_STOP();
	if (1)
	{
		led_normal_error=LED_OK;
	}
	return led_normal_error;
}
LED_Error LED_YELLOW_BOTH(void)
{
  LED_Error led_yellow_error=LED_OK;
TIMER0_MODE_INIT(MODE_NORMAL,4000);
TIMERO_PRESCALER_INIT(PRESCALER_1024);
TIMER0_OV_Interrupt_Enable();
	while ((TIFR & (1<<TOV0)) == 0)
	{
		LED_blink_mode(LED_CAR_YELLOW_PORTA,LED_CAR_YELLOW_PIN,CAR_MODE);
		LED_blink_mode(LED_PEDSTRAIN_YELLOW_PORTB,LED_PEDSTRAIN_YELLOW_PIN,PEDASTRAIN_MODE);
	}
    TIMER0_STOP();
	TIMER0_Clear_ovf_Flag();
	LED_OFF(LED_CAR_YELLOW_PORTA,LED_CAR_YELLOW_PIN);
	LED_OFF(LED_PEDSTRAIN_YELLOW_PORTB,LED_PEDSTRAIN_YELLOW_PIN);
 if (1)
 {
	 led_yellow_error=LED_OK;
 }
 return led_yellow_error=LED_OK;
}



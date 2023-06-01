/*
 * app.c
 *
 * Created: 2/18/2023 10:09:18 PM
 *  Author: shehab mohamed shawki 
 */ 
#include "App.h"
/************************************************************************/
/* MAIN Function for application                                        */
/************************************************************************/
uint8_t ButtonStaute;
/************************************************************************/
/* Function Helper for application                                      */
/************************************************************************/
uint8_t counter;
/************************************************************************/
uint8_t FLAG_PEDSTRAIN=0;
uint8_t FLAG_CAR=0;
/************************************************************************/
uint8_t RED_CAR_FLAG=0;
uint8_t YELLOW_CAR_FLAG=0;
uint8_t GREEN_CAR_FLAG=0;

void Timer_OVERFLOW(void){
	if(RED_CAR_FLAG == HIGH)
	{
		//  cars red on and pedestrian green on for 5 seconds
		LED_ON(LED_CAR_RED_PORTA,LED_CAR_RED_PIN);
		LED_ON(LED_PEDSTRAIN_GREEN_PORTB, LED_PEDSTRAIN_GREEN_PIN);
		LED_blink_mode(LED_CAR_RED_PORTA,LED_CAR_RED_PIN,CAR_MODE);

	    // BOTH IS OFF  
		LED_OFF(LED_CAR_RED_PORTA,LED_CAR_RED_PIN);
		LED_YELLOW_BOTH();
        // GREEN IS OFF , RED IS ON . 
		LED_OFF(LED_PEDSTRAIN_GREEN_PORTB, LED_PEDSTRAIN_GREEN_PIN);
		LED_ON(LED_CAR_RED_PORTA,LED_CAR_RED_PIN);
		LED_ON(LED_PEDSTRAIN_GREEN_PORTB, LED_PEDSTRAIN_GREEN_PIN);
		LED_blink_mode(LED_PEDSTRAIN_RED_PORTB,LED_PEDSTRAIN_RED_PIN,PEDASTRAIN_MODE);
		// 4. cars green off & both yellow led blink for 5 seconds and pedestrian red still on
		LED_OFF(LED_PEDSTRAIN_GREEN_PORTB, LED_PEDSTRAIN_GREEN_PIN);
		LED_NORMAL_DELAY();

		// 5. cars led on and back to normal mode & pedestrian red is still on
		LED_ON(LED_CAR_RED_PORTA,LED_CAR_RED_PIN);
	}
   if(YELLOW_CAR_FLAG == HIGH)
	{
	     LED_YELLOW_BOTH();
		LED_OFF(LED_CAR_RED_PORTA,LED_CAR_RED_PIN);
		LED_ON(LED_PEDSTRAIN_GREEN_PORTB, LED_PEDSTRAIN_GREEN_PIN);
		LED_NORMAL_DELAY();
		LED_OFF(LED_CAR_RED_PORTA,LED_CAR_RED_PIN);
	    LED_YELLOW_BOTH();
		// 4. pedestrian green off & cars green on and pedestrian red on for 5 seconds
		LED_OFF(LED_PEDSTRAIN_GREEN_PORTB, LED_PEDSTRAIN_GREEN_PIN);
		LED_ON(LED_PEDSTRAIN_GREEN_PORTB,LED_PEDSTRAIN_GREEN_PIN);
		LED_ON(LED_CAR_RED_PORTA,LED_CAR_RED_PIN);
	    LED_NORMAL_DELAY();

		// 5. cars green off & pedestrian red still on & yellow traffic blinks and back to normal mode
		LED_OFF(LED_PEDSTRAIN_GREEN_PORTB, LED_PEDSTRAIN_GREEN_PIN);
		LED_NORMAL_DELAY();
	}
  if(GREEN_CAR_FLAG == HIGH)
	{
		LED_YELLOW_BOTH();
		LED_OFF(LED_CAR_GREEN_PORTA,LED_CAR_GREEN_PIN);
		LED_OFF(LED_PEDSTRAIN_RED_PORTB,LED_PEDSTRAIN_RED_PIN);
		LED_ON(LED_CAR_RED_PORTA,LED_CAR_RED_PIN);
		LED_ON(LED_PEDSTRAIN_GREEN_PORTB, LED_PEDSTRAIN_GREEN_PIN);
	    LED_NORMAL_DELAY();
		LED_OFF(LED_CAR_RED_PORTA,LED_CAR_RED_PIN);
		LED_YELLOW_BOTH();
		// 4. pedestrian green off & cars green on and pedestrian red on for 5 seconds & back to normal mode
		LED_OFF(LED_PEDSTRAIN_GREEN_PORTB, LED_PEDSTRAIN_GREEN_PIN);
		LED_ON(LED_PEDSTRAIN_GREEN_PORTB, LED_PEDSTRAIN_GREEN_PIN);
		LED_ON(LED_PEDSTRAIN_RED_PORTB,LED_PEDSTRAIN_RED_PIN);
		 LED_NORMAL_DELAY();
	}
}

/************************************************************************/
/*  INIT FUNCTION                                                       */
/************************************************************************/
void APP_INIT(void){
         /********************  Initialization of CAR LEDS  **************************************/      
        LED_Init(LED_CAR_RED_PORTA,LED_CAR_RED_PIN);
        LED_Init(LED_CAR_YELLOW_PORTA,LED_CAR_YELLOW_PIN);
        LED_Init(LED_CAR_GREEN_PORTA,LED_CAR_GREEN_PIN);
         /********************* Initialization of pedestrians LEDS  *******************************/
        LED_Init(LED_PEDSTRAIN_RED_PORTB,LED_PEDSTRAIN_RED_PIN);
        LED_Init(LED_PEDSTRAIN_YELLOW_PORTB,LED_PEDSTRAIN_YELLOW_PIN);
        LED_Init(LED_PEDSTRAIN_GREEN_PORTB,LED_PEDSTRAIN_GREEN_PIN);
         /********************* Initialization of  BUTTON INTERRPT  ******************************/
         BUTTON_INIT(BUTTON_INT_PORTD,BUTTON_INT_PIND2);
        // SEI FUNCTION initialization 
         //  sei();
         /**************************** Timer 0 **********************/
	      TIMER0_MODE_INIT(MODE_NORMAL,1000); // Select Mode of timer0.
	      TIMERO_PRESCALER_INIT(NO_PRESCALER);
	      TIMER0_OV_Interrupt_Enable();
	      TIMER0_OV_SETCALLBACK(Timer_OVERFLOW);
	    /******************external interrupt INT0*******************/
	      EXternal_INT0_Enable();
	      EXternal_INT0_Trigger_Edge(FALLING_EDGE);
		  BUTTON_interrupt();
}
void APP_START(void){
	LED_ON(LED_CAR_RED_PORTA,LED_CAR_RED_PIN);
	LED_OFF(LED_CAR_GREEN_PORTA, LED_CAR_GREEN_PIN);
	_delay_ms(5000);
	for (int i=0;i<5;i++)
	{
		LED_ON(LED_CAR_YELLOW_PORTA, LED_CAR_YELLOW_PIN);
		_delay_ms(500);
		LED_OFF(LED_CAR_YELLOW_PORTA, LED_CAR_YELLOW_PIN);
		_delay_ms(500);
	}
	LED_OFF(LED_CAR_RED_PORTA,LED_CAR_RED_PIN);
	LED_ON(LED_CAR_GREEN_PORTA, LED_CAR_GREEN_PIN);
	LED_OFF(LED_CAR_RED_PORTA,LED_CAR_RED_PIN);
	_delay_ms(5000);
	for (int i=0;i<5;i++)
	{
		LED_ON(LED_CAR_YELLOW_PORTA, LED_CAR_YELLOW_PIN);
		_delay_ms(500);
		LED_OFF(LED_CAR_YELLOW_PORTA, LED_CAR_YELLOW_PIN);
		_delay_ms(500);
	}
  
	}



/*



/**NORMAL MODE **
if(FLAG_PEDSTRAIN == 0)
{
	LED_ON(LED_CAR_GREEN_PORTA, LED_CAR_GREEN_PIN);
	GREEN_CAR_FLAG = HIGH;
	LED_ON(LED_PEDSTRAIN_RED_PORTB,LED_PEDSTRAIN_RED_PIN);
	LED_NORMAL_DELAY();
	LED_OFF(LED_CAR_GREEN_PORTA, LED_CAR_GREEN_PIN);
	GREEN_CAR_FLAG = 0;
	LED_YELLOW_BOTH();
	LED_ON(LED_CAR_RED_PORTA,LED_CAR_RED_PIN);
	RED_CAR_FLAG = 0;
	LED_OFF(LED_PEDSTRAIN_RED_PORTB,LED_PEDSTRAIN_RED_PIN);
	LED_ON(LED_PEDSTRAIN_GREEN_PORTB, LED_PEDSTRAIN_GREEN_PIN);
	LED_NORMAL_DELAY();
	if(YELLOW_CAR_FLAG == 2)
	{
		LED_OFF(LED_CAR_GREEN_PORTA,LED_CAR_GREEN_PIN);
		LED_OFF(LED_CAR_RED_PORTA,LED_CAR_RED_PIN);
		LED_NORMAL_DELAY();
	}
	if(GREEN_CAR_FLAG == 3)
	{
		LED_OFF(LED_PEDSTRAIN_YELLOW_PORTB,LED_PEDSTRAIN_YELLOW_PIN);
		LED_OFF(LED_CAR_RED_PORTA,LED_CAR_RED_PIN);
		LED_YELLOW_BOTH();
	}
	
}
*/












 
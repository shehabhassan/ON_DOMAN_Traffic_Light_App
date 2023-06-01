/*
 * Registers.h
 *
 * Created: 2/18/2023 6:44:08 PM
 *  Author: shehab Mohamed shawki 
 */ 
/************************************************************************/
/* Define all Micro controller Registers                                */
/************************************************************************/

#ifndef REGISTERS_H_
#define REGISTERS_H_
/************************************************************************/
/* DIO Register  For Atmega32 Micro controller                          */
/************************************************************************/
#include "Types_def.h"

// PORTA define of registers .  
#define PORTA *((volatile uint8_t*)0x3B)
#define DDRA  *((volatile uint8_t*)0x3A)
#define PINA  *((volatile uint8_t*)0x39) 

// PORTB define of registers .
#define PORTB *((volatile uint8_t*)0x38)
#define DDRB  *((volatile uint8_t*)0x37)
#define PINB  *((volatile uint8_t*)0x36)

// PORTC defines of registers .
#define PORTC *((volatile uint8_t*)0x35)
#define DDRC  *((volatile uint8_t*)0x34)
#define PINC  *((volatile uint8_t*)0x33)

// PORTD defines of registers .
#define PORTD *((volatile uint8_t*)0x32)
#define DDRD  *((volatile uint8_t*)0x31)
#define PIND  *((volatile uint8_t*)0x30)

/************************************************************************/
/*  Configuration of  Register Timer 0 - TCCR0                          */
/************************************************************************/
#define TCNT0   (*(volatile unsigned char*)0x52)
#define TCCR0   (*(volatile unsigned char*)0x53)

/************************************************************************/
/*Configuration of  Register Timer 0 - TIMSK                            */
/************************************************************************/
#define TIFR    (*(volatile unsigned char*)0x58)
#define TIMSK   (*(volatile unsigned char*)0x59)
#define OCR0    (*(volatile unsigned char*)0x5C)
/************************************************************************/
/*     External interrupt  0                                            */
/************************************************************************/
#define MCUCSR   (*(volatile unsigned char*)0x54) //control register
#define MCUCR    (*(volatile unsigned char*)0x55) //control and statues register
#define GICR     (*(volatile unsigned char*)0x5B) //general interrupt control register
#define GIFR     (*(volatile unsigned char*)0x5A) //general interrupt Flag register

#endif /* REGISTERS_H_ */
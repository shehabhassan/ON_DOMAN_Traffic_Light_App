/*
 * BIT_FUN.h
 *
 * Created: 2/18/2023 7:19:31 PM
 *  Author: sheha
 */ 


#ifndef BIT_FUN_H_
#define BIT_FUN_H_
/************************************************************************/
/* BIT FUNCTION FOR Registers                                           */
/************************************************************************/

#define  SET(PIN,N)    (PIN |= (1<<N))
#define  CLEAR(PIN,N)  (PIN &=~(1<<N))
#define  TOGGLE(PIN,N) (PIN ^= (1<<N))

/************************************************************************/
/* READ DATA FROM SELSCTING PORT AND PINS                               */
/************************************************************************/
#define  READ(PIN,N)   (PIN &(1<<N)>>N)
#endif /* BIT_FUN_H_ */
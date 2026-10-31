/*
 * DIO_INTERFACE.h
 *
 * Created: 17/10/2026 8:47:08 PM
 *  Author: HP
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
#include "../../LIB/STD_TYPE.h"
#include "DIO_REGISTER.h"

#define DIO_u8INPUT 0
#define DIO_u8OUTPUT 1

#define DIO_u8PIN_HIGH 1
#define DIO_u8PIN_LOW 0

#define DIO_u8PORT_HIGH 1
#define DIO_u8PORT_LOW 0

#define DIO_u8PORTA 0
#define DIO_u8PORTB 1
#define DIO_u8PORTC 2
#define DIO_u8PORTD 3

#define DIO_u8PIN0 0
#define DIO_u8PIN1 1
#define DIO_u8PIN2 2
#define DIO_u8PIN3 3
#define DIO_u8PIN4 4
#define DIO_u8PIN5 5
#define DIO_u8PIN6 6
#define DIO_u8PIN7 7

u8 DIO_u8SetPinDirection(u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8Direction);

u8 DIO_u8SetPortDirection(u8 copy_u8Port, u8 copy_u8Direction) ;

u8 DIO_u8SetPinValue(u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8Value);

u8 DIO_u8SetPortValue(u8 copy_u8Port, u8 copy_u8Value);

u8 DIO_u8GetPinValue(u8 copy_u8Port, u8 copy_u8Pin, u8* copy_u8Value);

u8 DIO_u8TogglePin(u8 copy_u8Port, u8 copy_u8Pin);



#endif /* DIO_INTERFACE_H_ */

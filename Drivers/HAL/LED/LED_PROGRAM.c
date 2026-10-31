/*
 * LED_PROGRAM.c
 *
 * Created: 19/10/2026 12:20:55 PM
 *  Author: HP
 */ 

#include "../../LIB/STD_TYPE.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_INTERFACE.h"
#include "LED_INTERFACE.h"
#include <stddef.h>

u8 LED_Init(LED_Configuration *target_Led)
{
	u8 Local_u8ErrorState = 0;
	
	if (target_Led != NULL)
	{
		DIO_u8SetPinDirection(target_Led->Port, target_Led->Pin, DIO_u8OUTPUT);
	} 
	else
	{
		Local_u8ErrorState = 1;
	}
	return Local_u8ErrorState;
}

u8 LED_Turnon(LED_Configuration *target_Led)
{
	u8 Local_u8ErrorState = 0;
	
	if (target_Led != NULL)
	{
		DIO_u8SetPinValue(target_Led->Port, target_Led->Pin,DIO_u8PIN_HIGH);
	} 
	else
	{
		Local_u8ErrorState = 1;
	}
	return Local_u8ErrorState;
}

u8 LED_Turnoff(LED_Configuration *target_Led)
{
	u8 Local_u8ErrorState = 0;
	
	if (target_Led != NULL)
	{
		DIO_u8SetPinValue(target_Led->Port,target_Led->Pin,DIO_u8PIN_LOW);
	} 
	else
	{
		Local_u8ErrorState = 1;
	}
	return Local_u8ErrorState;
}

u8 LED_Toggle(LED_Configuration *target_Led)
{
	u8 Local_u8ErrorState = 0;
	
	if (target_Led != NULL)
	{
		DIO_u8TogglePin(target_Led->Port, target_Led->Pin);
	} 
	else
	{
		Local_u8ErrorState = 1;
	}
	return Local_u8ErrorState;
}

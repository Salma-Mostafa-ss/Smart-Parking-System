/*
 * SSD_PROGRAM.c
 *
 * Created: 17/10/2026 8:48:53 PM
 *  Author: HP
 */ 

#include "../../LIB/STD_TYPE.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_INTERFACE.h"
#include "SSD_INTERFACE.h"
#include <stddef.h>

// common_cathode
static const u8 SSD_Numbers[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,
                                   0x6D, 0x7D, 0x07, 0x7F, 0x6F};

u8 SSD_u8Init(SSD_Configuration * target_SSD)
{
	u8 Local_u8ErrorState = 0;
	if (target_SSD != NULL)
	{
		DIO_u8SetPortDirection(target_SSD->DataPort, 0xFF);
	} 
	else
	{
		Local_u8ErrorState = 1;
	}
	return Local_u8ErrorState;
}

u8 SSD_u8SetNumber(SSD_Configuration * target_SSD, u8 target_number)
{
	u8 Local_ErrorState = 0;
	if (target_SSD != NULL && target_number <= 9)
	{
		if (target_SSD->CommonType == COMMON_CATHODE)
		{
			DIO_u8SetPortValue(target_SSD->DataPort, SSD_Numbers[target_number]);
		} 
		else if (target_SSD->CommonType == COMMON_ANODE)
		{
			DIO_u8SetPortValue(target_SSD->DataPort, ~SSD_Numbers[target_number]);
		} 
		else
		{
			Local_ErrorState = 1;
		}
	} 
	else
	{
		Local_ErrorState = 1;
	}
	return Local_ErrorState;
}
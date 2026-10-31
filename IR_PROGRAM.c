/*
 * IR_PROGRAM.c
 *
 * Created: 17/10/2026 8:50:48 PM
 *  Author: HP
 */ 

#include "../../LIB/STD_TYPE.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_INTERFACE.h"
#include "IR_INTERFACE.h"
#include <stddef.h>
u8 IR_u8Init(IRSensor_Configuration * sensor)
{
	u8 Local_u8ErroState = 0;
	
	if (sensor != NULL)
	{
		DIO_u8SetPinDirection(sensor->Port,sensor->Pin,DIO_u8INPUT);
	} 
	else
	{
		Local_u8ErroState = 1;
	}
	return Local_u8ErroState;
}

u8 IR_u8GetState(IRSensor_Configuration * sensor)
{
	u8 Sensor_Value = 0;
	
	if (sensor != NULL)
	{
		DIO_u8GetPinValue(sensor->Port,sensor->Pin, &Sensor_Value);
	} 
	return Sensor_Value;
}
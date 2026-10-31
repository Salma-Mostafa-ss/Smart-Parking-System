/*
 * DCMOTOR_PROGRAM.c
 *
 * Created: 17/10/2026 8:52:05 PM
 *  Author: HP
 */ 

#include <stddef.h>
#include "../../LIB/STD_TYPE.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_INTERFACE.h"

#include "DCMOTOR_INTERFACE.h"

u8 DCMotor_u8Init(DCMotor_Configuration * target_motor)
{
	u8 Local_u8ErrorState1 = DIO_u8SetPinDirection(target_motor->Port,target_motor->Pin1,1);
	u8 Local_u8ErrorState2 = DIO_u8SetPinDirection(target_motor->Port,target_motor->Pin2,1);
	
	return Local_u8ErrorState2 || Local_u8ErrorState1;
}

u8 DCMotor_u8Rotate_Direction1(DCMotor_Configuration * target_motor)
{
	u8 Local_u8ErrorState1 = DIO_u8SetPinValue(target_motor->Port,target_motor->Pin1,1);
	u8 Local_u8ErrorState2 = DIO_u8SetPinValue(target_motor->Port,target_motor->Pin2,0);
	
	return Local_u8ErrorState2 || Local_u8ErrorState1;
}

u8 DCMotor_u8Rotate_Direction2(DCMotor_Configuration * target_motor)
{
	u8 Local_u8ErrorState1 = DIO_u8SetPinValue(target_motor->Port,target_motor->Pin1,0);
	u8 Local_u8ErrorState2 = DIO_u8SetPinValue(target_motor->Port,target_motor->Pin2,1);
	
	return Local_u8ErrorState2 || Local_u8ErrorState1;
}

u8 DCMotor_u8Stop(DCMotor_Configuration * target_motor)
{
	u8 Local_u8ErrorState1 = DIO_u8SetPinValue(target_motor->Port,target_motor->Pin1,0);
	u8 Local_u8ErrorState2 = DIO_u8SetPinValue(target_motor->Port,target_motor->Pin2,0);
	
	return Local_u8ErrorState2 || Local_u8ErrorState1;
}
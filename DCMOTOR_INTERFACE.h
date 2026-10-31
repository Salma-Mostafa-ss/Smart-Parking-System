/*
 * DCMOTOR_INTERFACE.h
 *
 * Created: 17/10/2026 8:51:35 PM
 *  Author: HP
 */ 


#ifndef DCMOTOR_INTERFACE_H_
#define DCMOTOR_INTERFACE_H_
#include "../../LIB/STD_TYPE.h"

#define DCMOTOR_u8PORTA 0
#define DCMOTOR_u8PORTB 1
#define DCMOTOR_u8PORTC 2
#define DCMOTOR_u8PORTD 3

#define DCMOTOR_u8PIN0  0
#define DCMOTOR_u8PIN1  1
#define DCMOTOR_u8PIN2  2
#define DCMOTOR_u8PIN3  3
#define DCMOTOR_u8PIN4  4
#define DCMOTOR_u8PIN5  5
#define DCMOTOR_u8PIN6  6
#define DCMOTOR_u8PIN7  7

#define DCMOTOR_DIR1    1
#define DCMOTOR_DIR2    2

typedef struct
{
	u8 Port;
	u8 Pin1;
	u8 Pin2;
}DCMotor_Configuration;

u8 DCMotor_u8Init(DCMotor_Configuration * target_motor);

u8 DCMotor_u8Rotate_Direction1(DCMotor_Configuration * target_motor);

u8 DCMotor_u8Rotate_Direction2(DCMotor_Configuration * target_motor);

u8 DCMotor_u8Stop(DCMotor_Configuration * target_motor);




#endif /* DCMOTOR_INTERFACE_H_ */
/*
 * Final_project.c
 *
 * Created: 20/10/2026 1:56:45 PM
 * Author : HP
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

#include "LIB/STD_TYPE.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/DIO/DIO_INTERFACE.h"
#include "HAL/DCMOTOR/DCMOTOR_INTERFACE.h"
#include "HAL/IR/IR_INTERFACE.h"
#include "HAL/LED/LED_INTERFACE.h"
#include "HAL/SSD/SSD_INTERFACE.h"

#define Max_Cars 4
#define Car_Detected 0
#define Gate_Speed 100
#define Gate_Move_Time 300

int main(void)
{
	
	MCUCSR |= (1 << JTD);
	MCUCSR |= (1 << JTD);

	LED_Configuration redled = {DIO_u8PORTA, DIO_u8PIN0}; //led struct
	LED_Init(&redled); // led as output
	
	SSD_Configuration ssd1 = {DIO_u8PORTC, COMMON_CATHODE}; //7Segment struct
	SSD_u8Init(&ssd1); // 7Segment as output
	
	IRSensor_Configuration IR_enter = {DIO_u8PORTA, DIO_u8PIN1}; //IR entering struct
	IR_u8Init(&IR_enter); //IR1 as input
	
	IRSensor_Configuration IR_exiting = {DIO_u8PORTA, DIO_u8PIN2}; //IR exiting struct
	IR_u8Init(&IR_exiting); //IR2 as input
	
	DCMotor_Configuration Motor = {DIO_u8PORTA, DIO_u8PIN4, DIO_u8PIN5}; //motor struct
	DCMotor_u8Init(&Motor); //motor as output
	
	
	DDRB |= (1 << PB3);
	TCCR0 = (1 << WGM00) | (1 << WGM01) | (1 << COM01) | (1 << CS01);
	OCR0 = Gate_Speed;
	
	u8 cars = 0;
	
	SSD_u8SetNumber(&ssd1, cars); // start from 0
	
	while (1)
	{
		
		if (IR_u8GetState(&IR_enter) == Car_Detected && cars < Max_Cars)
		{
			
			DCMotor_u8Rotate_Direction1(&Motor);
			_delay_ms(Gate_Move_Time);
			DCMotor_u8Stop(&Motor);
			
			while (IR_u8GetState(&IR_exiting) != Car_Detected);
			while (IR_u8GetState(&IR_exiting) == Car_Detected);
			
			cars++;
			SSD_u8SetNumber(&ssd1, cars);
			
			_delay_ms(Gate_Move_Time);
			DCMotor_u8Rotate_Direction2(&Motor);
			_delay_ms(Gate_Move_Time);
			DCMotor_u8Stop(&Motor);
			
			_delay_ms(500);
		}
		
		else if (IR_u8GetState(&IR_exiting) == Car_Detected && cars > 0)
		{
			
			DCMotor_u8Rotate_Direction1(&Motor);
			_delay_ms(Gate_Move_Time);
			DCMotor_u8Stop(&Motor);
			
			
			while (IR_u8GetState(&IR_enter) != Car_Detected);
			while (IR_u8GetState(&IR_enter) == Car_Detected);
			
			cars--;
			SSD_u8SetNumber(&ssd1, cars);
			
			_delay_ms(Gate_Move_Time);
			DCMotor_u8Rotate_Direction2(&Motor);
			_delay_ms(Gate_Move_Time);
			DCMotor_u8Stop(&Motor);
			
			_delay_ms(500); 
		}
		
		if (cars >= Max_Cars)
		{
			LED_Turnon(&redled);
		}
		else
		{
			LED_Turnoff(&redled);
		}
	}
}
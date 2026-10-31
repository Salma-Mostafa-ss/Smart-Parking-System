/*
 * SSD_INTERFACE.h
 *
 * Created: 17/10/2026 8:49:14 PM
 *  Author: HP
 */ 


#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_
#include "../../LIB/STD_TYPE.h"

#define COMMON_CATHODE 1
#define COMMON_ANODE 0

#define SSD_U8PORTA 0
#define SSD_U8PORTB 1
#define SSD_U8PORTC 2
#define SSD_U8PORTD 3

#define SSD_U8PIN0 0
#define SSD_U8PIN1 1
#define SSD_U8PIN2 2
#define SSD_U8PIN3 3
#define SSD_U8PIN4 4
#define SSD_U8PIN5 5
#define SSD_U8PIN6 6
#define SSD_U8PIN7 7

typedef struct  
{
	u8 DataPort;
	u8 CommonType;
	
}SSD_Configuration;

u8 SSD_u8Init(SSD_Configuration * target_SSD);

u8 SSD_u8SetNumber(SSD_Configuration * target_SSD, u8 target_number);





#endif /* SSD_INTERFACE_H_ */
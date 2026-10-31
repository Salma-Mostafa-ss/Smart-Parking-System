/*
 * LED_INTERFACE.h
 *
 * Created: 19/10/2026 12:20:30 PM
 *  Author: HP
 */ 


#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_
#include "../../LIB/STD_TYPE.h"

typedef struct{
	u8 Port;
	u8 Pin;
}LED_Configuration;

u8 LED_Init(LED_Configuration *target_Led);

u8 LED_Turnon(LED_Configuration *target_Led);

u8 LED_Turnoff(LED_Configuration *target_Led);

u8 LED_Toggle(LED_Configuration *target_Led);



#endif /* LED_INTERFACE_H_ */

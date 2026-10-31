/*
 * IR_INTERFACE.h
 *
 * Created: 17/10/2026 8:51:04 PM
 *  Author: HP
 */ 


#ifndef IR_INTERFACE_H_
#define IR_INTERFACE_H_

typedef struct
{
	u8 Port;
	u8 Pin;
}IRSensor_Configuration;

u8 IR_u8Init(IRSensor_Configuration * sensor);

u8 IR_u8GetState(IRSensor_Configuration * sensor);



#endif /* IR_INTERFACE_H_ */
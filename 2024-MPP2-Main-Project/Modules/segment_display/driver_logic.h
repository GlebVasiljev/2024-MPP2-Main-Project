#ifndef DRIVER_LOGIC_H_
#define DRIVER_LOGIC_H_
#include "avr/io.h"
#include "counting_time.h"
#define BCD_DIGIT_COUNT 10
#define BCD_INTEGREITED_CIRCUIT_USED

void MY_ShowTime(time_t *time);
void MY_Init_Time(time_t *time);
void MY_ShiftRegister(uint8_t bit_value);
void MY_ShiftRegister_ClockPulse();
void MY_ShiftRegister_Clear();

#ifdef BCD_INTEGREITED_CIRCUIT_USED
	#define DIGIT0		0x00 
	#define DIGIT1		0x01
	#define DIGIT2		0x02
	#define DIGIT3		0x03
	#define DIGIT4		0x04
	#define DIGIT5		0x05
	#define DIGIT6		0x06
	#define DIGIT7		0x07
	#define DIGIT8		0x08
	#define DIGIT9		0x09
#endif



#endif /* DRIVER_LOGIC_H_ */
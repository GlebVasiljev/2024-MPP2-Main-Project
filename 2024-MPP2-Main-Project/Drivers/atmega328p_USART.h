/*
 * atmega328p_USART.h
 *
 * Created: 04/04/2024 09:44:17
 *  Author: Student
 */ 
#include "avr/io.h"

#ifndef ATMEGA328P_USART_H_
#define ATMEGA328P_USART_H_

void My_Init_USART();
void My_USART0_TransmitByte(uint8_t symbol);
uint8_t My_USART0_ReciveByte();
uint8_t My_USART0_ReviveString(uint8_t data_arr, uint8_t lenght);


#endif /* ATMEGA328P-USART_H_ */
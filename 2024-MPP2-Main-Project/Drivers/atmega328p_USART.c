/*
 * atmega328p_USART.c
 *
 * Created: 04/04/2024 09:44:26
 *  Author: Student
 */ 
#include "atmega328p_USART.h"

void My_Init_USART()
{
	// Iestate simbolu p?rs?ta ?trumu 9600 baud
	UBRR0 = 103; 
	
	// RXEN0 - en uztver?šanas da?u
	// TXEN - en raid?šanas da?u
	// RXCIE - en RX p?rtraukumu 
	UCSR0B = (1 << RXEN0) | (1 << TXEN0) | ( 1 << RXCIE0);
	
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

void My_USART0_TransmitByte(uint8_t symbol)
{
	// if transmitter buffer !empty -> write data in symbol
	while(!(UCSR0A) & (1 << UDRE0));
	UDR0 = symbol;
}

uint8_t My_USART0_ReciveByte()
{
	uint8_t data = UDR0;
	return data;
}
uint8_t My_USART0_ReviveString(uint8_t data_arr, uint8_t lenght)
{
	
}
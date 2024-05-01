/*
 * atmega328p_USART.c
 *
 * Created: 04/04/2024 09:44:26
 *  Author: Student
 */ 
#define Test_Command "<TEST0>"

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

int My_USART0_CheckString(uint8_t checkChar, uint8_t position, uint8_t buffer_len)
{
	// check < in the begining
	if(position == 0 && checkChar == '<')
	{
		return 1;
	}
	else if (position == 0 && checkChar != '<')
	{
		return 0;
	}
	
	// check > in the end
	if(position == buffer_len-2 && checkChar == '>')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

uint8_t My_USART0_ReciveString(uint8_t *data_arr, uint8_t lenght)
{
	static int i = 0;
	data_arr[i] = My_USART0_ReciveByte();

	if(i == 0)
	{
		if(My_USART0_CheckString(data_arr[0],i,lenght) == 1)
		{
			i++;
		}
		
	}
	else 
	{
		i++;
	}
	
	

	if(i == lenght-1)
	{
		i = 0;		
		return 1;
	}
	else
	{
		return 0;
	}

}

uint8_t Process_command(uint8_t *data_arr )
{
	char test_str[8];
	strcpy(test_str, Test_Command); 
	if( strcmp(data_arr, Test_Command) == 0 ) // compare USART input with pre-defined command
	{
		return 1; 
	}
	else
	{

		return 0;
	}
}


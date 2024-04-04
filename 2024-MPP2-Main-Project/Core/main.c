/*
 * 2024-MPP2-Main-Project.c
 *
 * Created: 04/04/2024 09:30:28
 * Author : Student
 */ 

#include "main.h"
#include "avr/interrupt.h"

int main(void)
{
	DDRB |= (1 << DDB5);
	
	My_Init_TIM1();
    My_TIM_Start(TIM1,TIM1_PRESCALER_FACTOR_1024);
	
	My_Init_USART();
	
	
	sei();
	
    while (1) 
    {
	
    }
}

ISR(TIMER1_COMPA_vect)
{
	
	static uint8_t data = 0x41;
	data++;
	if(data == 0x5B) {
		data = 0x41;
	}
	uint8_t data_to_send = data;

	
	My_USART0_TransmitByte(data_to_send);
	PORTB ^= (1 << PORTB5);
}
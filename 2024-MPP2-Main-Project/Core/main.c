/*
 * 2024-MPP2-Main-Project.c
 *
 * Created: 04/04/2024 09:30:28
 * Author : Student
 */ 

#include "main.h"
#include "avr/interrupt.h"
#define USART_Buffer_lenght 8

uint8_t data;
uint8_t data_arr[5] = {0x0A, 0x0B, 0x0C, 0x0E, 0x0F};
uint8_t *ptr;
uint8_t *ptr_to_var;

uint8_t MCU = 0xAF;

uint8_t data_buffer[USART_Buffer_lenght];

static uint32_t x = 0;




//time_t Time = { 0 }; Set all var value -> 0

//time_t *ptr_to_Time;


void test_function(void);


int main(void)
{

	DDRD = 0b11110000;
	DDRB = 0b00001111;
	
	//My_Init_TIM0();
	My_Init_TIM1();
	My_Init_TIM2();
    My_TIM_Start(TIM2,TIM2_PRESCALER_FACTOR_64);
	My_TIM_Start(TIM1,TIM1_PRESCALER_FACTOR_1024);
	
	My_Init_USART();

	//set_default_time(&Time);
	My_User_Clock_Set(My_User_GetTime(),1,10,10,0);
	
	
	sei();
	
	while(1)
	{
		
	}
	
}




// Timer B

ISR(TIMER0_COMPB_vect)
{	
	
}

ISR(TIMER1_COMPA_vect)
{
	static uint8_t counter = 0;
	PORTD = counter << 4;
	counter++;
	if( counter == 10)
	{
		counter = 0;
	}
	
	
}

ISR(TIMER2_COMPA_vect)
{
	counting_time_forward_miliseconds(My_User_GetTime());
	
	//counting_time_backward_miliseconds(My_User_GetTime());
}

ISR(USART_RX_vect)
{
	//data = My_USART0_ReciveByte();
	if(My_USART0_ReciveString(data_buffer, USART_Buffer_lenght) == 1)
	{
		Process_command(data_buffer);
	}

	
	PORTB ^= (1 << PORTB5);
}
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

/*
typedef struct example
{
	uint8_t id;
	
	uint16_t x;
	uint16_t y;
	uint16_t z;
}example_t;


example_t sensor_data;
example_t *ptr_to_struct;
*/


time_t Time = { 0 }; //Set all var value -> 0

//time_t *ptr_to_Time;


void test_function(void);


int main(void)
{

	DDRD = 0b11110000;
	DDRB = 0b00001111;
	
	//My_Init_TIM0();
	//My_Init_TIM1();
	My_Init_TIM2();
    My_TIM_Start(TIM2,TIM2_PRESCALER_FACTOR_64);
	
	My_Init_USART();

	
	sei();
	
	while(1)
	{
		
	}
	
}

void test_function()
{
	
	
}

// TO DO Ierakstit atseviska faila



// Timer B

ISR(TIMER0_COMPB_vect)
{	
	
}

ISR(TIMER1_COMPA_vect)
{
	
}

ISR(TIMER2_COMPA_vect)
{
	counting_time_forward_miliseconds(&Time);
	
	//counting_time_backward_miliseconds(&Time);
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
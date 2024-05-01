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

typedef struct{
	int16_t ms;
	int8_t seconds;
	int8_t minutes;
	int8_t hours;

}time_t;

time_t Time = { 0 }; //Set all var value -> 0

//time_t *ptr_to_Time;


void test_function(void);


int main(void)
{

	DDRD = 0b11110000;
	DDRB = 0b00001111;
	
	My_Init_TIM1();
	My_Init_TIM0();
    My_TIM_Start(TIM1,TIM1_PRESCALER_FACTOR_1024);
	
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
void counting_time_backward_miliseconds(time_t *ptr_to_Time)
{
	ptr_to_Time->ms--;

	if (ptr_to_Time->ms < 0)
	{
		ptr_to_Time->ms = 1000;
		ptr_to_Time->seconds--;
	}

	if (ptr_to_Time->seconds < 0)
	{
		ptr_to_Time->seconds = 59;
		ptr_to_Time->minutes--;
	}

	if (ptr_to_Time->minutes < 0)
	{
		ptr_to_Time->minutes = 59;
		ptr_to_Time->hours--;
	}

	if (ptr_to_Time->hours < 0)
	{
		ptr_to_Time->ms = 0;
		ptr_to_Time->seconds = 0;
		ptr_to_Time->minutes = 0;
		ptr_to_Time->hours = 0;
	}
}

// TO DO Ierakstit atseviska faila
void counting_time_forward_miliseconds(time_t *ptr_to_Time)
{
	ptr_to_Time->ms++;

	if (ptr_to_Time->ms >= 1000)
	{
		ptr_to_Time->seconds++;
	}

	if (ptr_to_Time->seconds >= 60)
	{
		ptr_to_Time->minutes++;
	}

	if (ptr_to_Time->minutes >= 60)
	{
		ptr_to_Time->hours++;
	}

	if (ptr_to_Time->hours >= 24)
	{
		ptr_to_Time->hours = 0;
	}
}

// Timer B

ISR(TIMER0_COMPB_vect)
{	
	counting_time_forward_miliseconds(&Time); 
	
	static uint8_t cathode = 0;
	uint8_t digit = Time.seconds;
	
	
	PORTD = digit << 4;
	PORTB = cathode; 
	
}

ISR(TIMER1_COMPA_vect)
{
	
	//counting_time_forward_miliseconds(&Time);
	Time.minutes = 14;
	counting_time_forward_miliseconds(&Time);
	static uint8_t cathode = 0;
	uint8_t digit = Time.seconds;


	PORTD = digit << 4;
	PORTB = cathode;
	/*
	static uint8_t data = 0x41;
	data++;
	if(data == 0x5B) {
		data = 0x41;
	}
	uint8_t data_to_send = data;

	
	My_USART0_TransmitByte(data_to_send);
	PORTB ^= (1 << PORTB5);
	*/
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
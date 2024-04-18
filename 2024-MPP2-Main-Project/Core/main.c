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

void test_function(void);
*/

int main(void)
{
	DDRB |= (1 << DDB5);
	
	My_Init_TIM1();
    My_TIM_Start(TIM1,TIM1_PRESCALER_FACTOR_1024);
	
	My_Init_USART();
	//test_function();
	
	sei();
	
    while (1) 
    {
	
    }
}

/*void test_function()
{
	ptr = &data_arr;
	ptr++;
	ptr++;
	*ptr = 0xFF;
	ptr_to_var = &MCU;
	
	ptr_to_struct = &sensor_data;
}
*/

ISR(TIMER1_COMPA_vect)
{
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
	My_USART0_ReciveString(data_buffer, USART_Buffer_lenght);
	

	
	PORTB ^= (1 << PORTB5);
}
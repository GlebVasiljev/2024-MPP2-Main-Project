#pragma once
#include "driver_logic.h"

static uint8_t bcd_chip_input[BCD_DIGIT_COUNT] =
{
	DIGIT0, DIGIT1, DIGIT2, DIGIT3, DIGIT4,
	DIGIT5, DIGIT6, DIGIT7, DIGIT8, DIGIT9
};

//static uint8_t mux[4] = {COMMON_PIN0 , COMMON_PIN1, COMMON_PIN3, COMMON_PIN4 };
static uint8_t digit_output_buffer[8];


static void split_time_number_for_segment_display(time_t *time);
static void show_digits_on_segment_display();
static void shift_register_shift_value(uint8_t value);
static void shift_register_clk_pulse();
static void shift_register_clear();

void MY_ShowTime(time_t *time)
{
	split_time_number_for_segment_display(time);
	show_digits_on_segment_display();
}

void MY_Init_Time(time_t *time)
{

	time->ms = 0;
	time->seconds = 11;
	time->minutes = 11;
	time->hours = 11;
	
}

void MY_ShiftRegister(uint8_t bit_value)
{
	shift_register_shift_value(bit_value);
}

void MY_ShiftRegister_ClockPulse()
{
	shift_register_clk_pulse();
}

void MY_ShiftRegister_Clear()
{
	shift_register_clear();
}

static void show_digits_on_segment_display()
{
	static uint8_t counter = 0;
	
	if(counter == 0)
	{
		PORTD = (PORTD & 0x0F) | (digit_output_buffer[counter] << 4);
		shift_register_shift_value(1);
	}


	if((counter > 0) && (counter < 8))
	{
		PORTD = (PORTD & 0x0F) | (digit_output_buffer[counter] << 4);
		shift_register_clk_pulse();
	}
	counter++;

	//0, 1, 2, 3, 4, 5, 6, 7
	if (counter > 8)
	{
		counter = 0;
	}
}

static void shift_register_shift_value(uint8_t value)
{
	if(value == 0)
	{
		PORTB &= ~(1 << PORTB0);
		shift_register_clk_pulse();
		PORTB &= ~(1 << PORTB0);
	}
	else if(value == 1)
	{
		PORTB |= (1 << PORTB0);
		shift_register_clk_pulse();
		PORTB &= ~(1 << PORTB0);
	}
}

static void shift_register_clk_pulse()
{
	//CLK High
	PORTB |= (1 << PORTB1);
	//CLK noilgums
	asm("nop");
	asm("nop");
	asm("nop");
	//CLK Low
	PORTB &= ~(1 << PORTB1);
	
}

static void split_time_number_for_segment_display(time_t *time)
{
	#ifdef BCD_INTEGREITED_CIRCUIT_USED 
	digit_output_buffer[0] = bcd_chip_input[time->ms % 100 / 10];
	digit_output_buffer[1] = bcd_chip_input[time->ms / 100];
	
	digit_output_buffer[2] = bcd_chip_input[time->seconds % 10];
	digit_output_buffer[3] = bcd_chip_input[time->seconds / 10];
	
	digit_output_buffer[4] = bcd_chip_input[time->minutes % 10];
	digit_output_buffer[5] = bcd_chip_input[time->minutes / 10];
	
	digit_output_buffer[6] = bcd_chip_input[time->hours % 10];
	digit_output_buffer[7] = bcd_chip_input[time->hours / 10];

	#endif
}

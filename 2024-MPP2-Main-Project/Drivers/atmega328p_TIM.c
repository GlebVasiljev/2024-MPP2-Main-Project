/*
 * atmega328p_tim.c
 *
 * Created: 04/04/2024 09:43:10
 *  Author: Student
 */ 
#include "atmega328p_TIM.h"


/**------------------------------------------------------------------
 * @brief Funkcija nodrošina taimera/skaitit?tja TIM0 darb?bas rež?mu
 * TIM0 izmanto 7 segmentu displeju kop?go katodu multipleks?šanai
*/
void My_Init_TIM0()
{
	
}

/**------------------------------------------------------------------
 * @brief Funkcija nodrošina taimera/skaitit?tja TIM1 darb?bas rež?mu
 * TIM1 izmanto 1 sekundes laikdeves nodrošinašanai
*/
void My_Init_TIM1()
{
	// Galvenais skait?šanas re?istrs
	TCNT1 = 0;
	
	// TIM1 salidzin?šanas re?istrs
	OCR1A = 15625;
	
	// Iestata darb?bas režimu MODE 4
	// TOP = OCR1A 
	TCCR1B  |= (1 << WGM12);
	
	// Specifisk? p?rtraukuma at?aušana
	TIMSK1	|= (1 << OCIE1A);
}

/**------------------------------------------------------------------
 * @brief Funkcija nodrošina taimera/skaitit?tja TIM2 darb?bas rež?mu
 * TIM2 izmanto hronomemetra un funkcionalit?tes nodrošin?šanai
*/
void My_Init_TIM2()
{
	
}


/**------------------------------------------------------------------
 * @brief Funkcija iesl?dz nor?dita taimera/skaitit?ja CS (clock select)
 * lai uzs?ktu skait?šanu re?istra TCNTx, kur x ir 0 / 1 / 2
 *
 * @param tim_name			taimera skaitit?ja nosaukums
 * @param prescailer_value  Dalit?ja 
*/
void My_TIM_Start(uint8_t tim_name, uint8_t prescailer_value)
{
	switch (tim_name)
	{
		case TIM0:
			TCCR0B &= 0xF8;
			TCCR0B |= prescailer_value;
		break;
		
		case TIM1:
			TCCR1B &= 0xF8;
			TCCR1B |= prescailer_value;
		break;
		
		case TIM2:
			TCCR2B &= 0xF8;
			TCCR2B |= prescailer_value;
		break;
		
		default:
		break;
	}
}

void My_TIM_Stop (uint8_t tim_name)
{
	switch(tim_name)
	{
		case TIM0:
			// TCCR0B &= ~(1 << CS02) | (1 << CS01) | ()
			TCCR0B &= 0xF8;
		break;
			
			
		case TIM1:
			TCCR1B &= 0xF8;
		break;
			
			
		case TIM2:
			TCCR2B &= 0xF8;
		break;
	}
}
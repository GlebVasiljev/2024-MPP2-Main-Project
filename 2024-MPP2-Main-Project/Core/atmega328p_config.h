/*
 * atmega328p_config.h
 *
 * Created: 04/04/2024 09:54:05
 *  Author: Student
 */ 


#ifndef ATMEGA328P_CONFIG_H_
#define ATMEGA328P_CONFIG_H_

#define MODULE_ENABLED_USART
#define MODULE_ENABLED_TIM

#ifdef MODULE_ENABLED_TIM
	#include "atmega328p_TIM.h"
#endif

#ifdef MODULE_ENABLED_USART
#include "atmega328p_USART.h"
#endif

#endif /* ATMEGA328P-CONFIG_H_ */
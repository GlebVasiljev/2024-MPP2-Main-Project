/*
 * counting_time.h
 *
 * Created: 16/05/2024 10:59:20
 *  Author: Student
 */ 


#ifndef COUNTING_TIME_H_
#define COUNTING_TIME_H_
#include "avr/io.h"

typedef struct{
	int16_t ms;
	int8_t seconds;
	int8_t minutes;
	int8_t hours;

}time_t;

time_t Time;

void counting_time_forward_miliseconds(time_t *Time);
void counting_time_backward_miliseconds(time_t *Time);




#endif /* COUNTING_TIME_H_ */
#ifdef counting_time_H_
#define counting_time_H_
#include "avr/io.h"

typedef struct{
	int16_t ms;
	int8_t seconds;
	int8_t minutes;
	int8_t hours;

}time_t;

time_t Time;
time_t *get_time();
void counting_time_forward_miliseconds(time_t *time);
void counting_time_backward_miliseconds(time_t *time);

#endif
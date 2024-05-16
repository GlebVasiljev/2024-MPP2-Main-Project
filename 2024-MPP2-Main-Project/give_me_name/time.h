
#ifndef TIME_H_
#define TIME_H_
#include "avr/io.h"

typedef struct{
	int16_t ms;
	int8_t seconds;
	int8_t minutes;
	int8_t hours;

}time_t;

time_t Time;

typedef struct{
	time_t time;
	
	int8_t day;
	int8_t month;
	int8_t year;
}time_data_t;

time_data_t Data;

enum
{
	active_user_clock,
	active_user_hronometr,
	active_user_timer,
	active_user_both	
};

void counting_time_forward_miliseconds(time_t *Time);
void counting_time_backward_miliseconds(time_t *Time);
void set_time(time_t *Time, uint8_t h, uint8_t m, uint8_t s, uint16_t ms);
void set_default_time(time_t *Time);



#endif /* TIME_H_ */
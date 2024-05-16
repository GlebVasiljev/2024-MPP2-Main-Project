#include "counting_time.h"


time_t *get_time()
{
	return Time; 
}

void counting_time_forward_miliseconds(time_t *time)
{
	time->ms++;

	if (time->ms >= 1000)
	{
		time->ms = 0;
		time->seconds++;
		
	}

	if (time->seconds >= 60)
	{
		time->seconds = 0;
		time->minutes++;
	}

	if (time->minutes >= 60)
	{
		time->minutes = 0;
		time->hours++;
	}

	if (time->hours >= 24)
	{
		time->hours = 0;
	}
}

void counting_time_backward_miliseconds(time_t *time)
{
	time->ms--;

	if (time->ms < 0)
	{
		time->ms = 1000;
		time->seconds--;
	}

	if (time->seconds < 0)
	{
		time->seconds = 59;
		time->minutes--;
	}

	if (time->minutes < 0)
	{
		time->minutes = 59;
		time->hours--;
	}

	if (time->hours < 0)
	{
		time->ms = 0;
		time->seconds = 0;
		time->minutes = 0;
		time->hours = 0;
	}
}
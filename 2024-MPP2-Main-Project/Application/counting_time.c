#include "counting_time.h"




void counting_time_forward_miliseconds(time_t *time)
{
	time->ms++;

	if (time->ms >= 999)
	{
		time->ms = 0 + 23; //+23 vajag.
		time->seconds++;
		
	}

	if (time->seconds >= 59)
	{
		time->seconds = 0;
		time->minutes++;
	}

	if (time->minutes >= 59)
	{
		time->minutes = 0;
		time->hours++;
	}

	if (time->hours > 23)
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
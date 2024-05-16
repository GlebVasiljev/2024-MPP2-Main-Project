#include "time.h"

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
		time->ms = 999;
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

void set_time(time_t *time, uint8_t h, uint8_t m, uint8_t s, uint16_t ms)
{
	time->hours = h;
	time->minutes = m;
	time->seconds = s;
	time->ms = ms;
}

void set_default_time(time_t *time)
{
	time->ms = 0;
	time->seconds = 0;
	time->minutes = 0;
	time->hours = 0;
}
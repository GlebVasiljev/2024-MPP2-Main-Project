#include "counting_time.h"


void counting_time_forward_miliseconds(time_t *ptr_to_Time)
{
	ptr_to_Time->ms++;

	if (ptr_to_Time->ms >= 1000)
	{
		ptr_to_Time->ms = 0;
		ptr_to_Time->seconds++;
		
	}

	if (ptr_to_Time->seconds >= 60)
	{
		ptr_to_Time->seconds = 0;
		ptr_to_Time->minutes++;
	}

	if (ptr_to_Time->minutes >= 60)
	{
		ptr_to_Time->minutes = 0;
		ptr_to_Time->hours++;
	}

	if (ptr_to_Time->hours >= 24)
	{
		ptr_to_Time->hours = 0;
	}
}

void counting_time_backward_miliseconds(time_t *ptr_to_Time)
{
	ptr_to_Time->ms--;

	if (ptr_to_Time->ms < 0)
	{
		ptr_to_Time->ms = 1000;
		ptr_to_Time->seconds--;
	}

	if (ptr_to_Time->seconds < 0)
	{
		ptr_to_Time->seconds = 59;
		ptr_to_Time->minutes--;
	}

	if (ptr_to_Time->minutes < 0)
	{
		ptr_to_Time->minutes = 59;
		ptr_to_Time->hours--;
	}

	if (ptr_to_Time->hours < 0)
	{
		ptr_to_Time->ms = 0;
		ptr_to_Time->seconds = 0;
		ptr_to_Time->minutes = 0;
		ptr_to_Time->hours = 0;
	}
}
#include "user_clock.h"
#include "time.h"
static time_t user_clock;


void My_User_Clock()
{
	counting_time_forward_miliseconds(&user_clock);
}

void My_User_Clock_Set(time_t *time, uint8_t h, uint8_t m, uint8_t s, uint16_t ms)
{
	set_time(time, h, m, s, ms);
}

void My_User_Clock_Set_Default()
{
	set_default_time(&user_clock);
}

time_t *My_User_GetTime()
{
	return &user_clock;
}
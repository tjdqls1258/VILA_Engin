#ifndef _TIME_H_
#define _TIME_H_

#include <Windows.h>

class Time
{
public:
	LARGE_INTEGER BeginTime, Frequency, EndTime;
	LARGE_INTEGER CurrentTime, LastTime;
	float FU_time = 0, tick = 0, U_time = 0; //FU_time = FixedUpdate_time, U_time = Update_time

	static Time* Instance_Time();
	void Reset_Time();
	float DelaTime();
};

#endif // !_TIME_H_

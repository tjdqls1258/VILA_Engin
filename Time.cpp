#include "Time.h"

Time* Time::Instance_Time()
{
	static Time instance_time;
	return &instance_time;
}

void Time::Reset_Time()
{
	if (FU_time >= 3)
	{
		QueryPerformanceCounter(&BeginTime);
		BeginTime = EndTime;
		FU_time = 0;
		QueryPerformanceCounter(&EndTime);
	}
	QueryPerformanceCounter(&LastTime);
	LastTime = CurrentTime;
	QueryPerformanceCounter(&EndTime);
}

float Time::DelaTime()
{
	float Delatime = (CurrentTime.QuadPart - LastTime.QuadPart) / tick;
	return Delatime;
}
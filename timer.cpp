#include "timer.hpp"

Timer::Timer()
{
	this->startTime = this->endTime = 0;
	this->t = (struct timeval *)malloc(sizeof(struct timeval));
  	this->z =(struct timezone *) malloc(sizeof(struct timezone));
}
void Timer::SetStartTime()
{
	gettimeofday(t,z);
	this->startTime = t->tv_sec;
}
void Timer::SetEndTime()
{
	gettimeofday(t,z);
	this->endTime = t->tv_sec;
}
int Timer::GetTotalTime()
{
	return this->endTime - this->startTime;
}

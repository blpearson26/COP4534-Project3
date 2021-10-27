#ifndef TIMER_HPP
#define TIMER_HPP
#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>  /*  for malloc */
#include <unistd.h>  // for sleep()
using namespace std;

class Timer {

private:
	int startTime;
	int endTime;
	struct timeval * t;
  	struct timezone * z;

public:
	Timer();
	void SetStartTime();
	void SetEndTime();
	int GetTotalTime();

};

#endif
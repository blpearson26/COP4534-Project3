#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>  /*  for malloc */
#include <unistd.h>  // for sleep()

void demo()
{
  struct timeval * t;
  struct timezone * z;

  t = (struct timeval *)malloc(sizeof(struct timeval));
  z =(struct timezone *) malloc(sizeof(struct timezone));
  for (int i = 0; i < 10; i++)
  { 
      gettimeofday(t,z);
      printf("time is %d seconds %d microseconds\n",t->tv_sec,t->tv_usec);  
      sleep(1);
  }
}

Time Time()
{
  demo();
}
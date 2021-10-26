#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>  /*  for malloc */
#include <unistd.h>  // for sleep()
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


static const int ARR_SIZE= 20;
float** distances = new float*[ARR_SIZE];
int NUMELEMENTS = 10;
float* s = new float[NUMELEMENTS];


void demo()
{
  struct timeval * t;
  struct timezone * z;

  t = (struct timeval *)malloc(sizeof(struct timeval));
  z =(struct timezone *) malloc(sizeof(struct timezone));
  for (int i = 0; i < 10; i++)
  { 
      gettimeofday(t,z);
      printf("\ntime is %d seconds %d microseconds\n",t->tv_sec,t->tv_usec);  
     // sleep(1);
  }
}
int GetDistances()
{
	ifstream inFS;
	inFS.open("distances.txt");
	if(inFS.is_open())
	{
		for(int i = 0; i < ARR_SIZE; ++i)
		{
			distances[i] = new float[ARR_SIZE];
			for(int j = 0; j < ARR_SIZE; ++j)
			{
				if(i == j)
					distances[i][j] = 0;
				else
					inFS >> distances[i][j];
			}
		}	
	}
	else
	{
		cout << "ERROR: Could not Open File!" << endl;
		return 0;
	}
}
void PrintDistances()
{
	for(int i = 0; i < 20; ++i)
	{
		cout << "|";
		for(int j = 0; j < 20; ++j)
		{
			cout << distances[i][j] << " | ";
		}
		cout << "\n------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	}
}
void printS()
{
	for(int i = 0; i < NUMELEMENTS; ++i)
	{
		cout << s[i] << " | ";
	}
}
void swap(int m, int k)
{
	float temp = s[m];
	s[m] = s[k];
	s[k] = temp;
}
void perm1(int permsThisCall) 
{
     int m, k, p , q, i;
     cout << "\nARRAY Before: " << endl;
     cout << "---------" << endl;
     printS();
     for(i = 1; i < permsThisCall; i++)
     {
       m = NUMELEMENTS-2;
       while(s[m]>s[m+1])
       {
          m = m - 1;
       }
       k = NUMELEMENTS-1;
       while(s[m] > s[k])
       {
          k = k - 1;
       }
       swap(m,k);
       p = m + 1;
       q = NUMELEMENTS-1;
       while( p < q)
       {
         swap(p,q);
         p++;
         q--;
       }
       cout << "\nARRAY After: " << endl;
       cout << "---------" << endl;
       printS();
     }
}



int main()
{

	GetDistances();
	PrintDistances();

	for(int i = 0; i < NUMELEMENTS; ++i)
	{
		s[i] = distances[0][i];
	}

	perm1(9);

	demo();
	return 0;
}
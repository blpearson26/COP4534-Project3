#include "bruteforce.hpp"

BruteForce::BruteForce(double** distances, int numElements)
{
	this->distances = distances;
	this->NUMELEMENTS = numElements;
	this->minCost = 9999;
	this->s = new int[NUMELEMENTS];
	//Fill s array
	for(int i = 0; i < NUMELEMENTS; ++i)
	{
		s[i] = i + 1;
	}
}
void BruteForce::Compute()
{
	
	int j = 0;
	int weight = 0;

	for(int i = 0; i < NUMELEMENTS; ++i)
	{
		weight += distances[j][s[i]];
		j = s[i];
	}

	weight += distances[j][0];
	minCost = min(minCost, weight);

}
void BruteForce::swap(int m, int k)
{
	int temp = s[m];
	s[m] = s[k];
	s[k] = temp;
}
void BruteForce::perm1(int permsThisCall) 
{
	t.SetStartTime();
    int m, k, p , q, i;

    for(i = 1; i < permsThisCall; i++)
    {
        t.SetEndTime();
		totalTime = t.GetTotalTime();
		if(totalTime >= MAXTIME)
		{
			cout << "RUNTIME EXCEEDED, EXITING PROGRAM!!" << endl;
			break;
		}
		else
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
       		Compute();
       	}
    }
}
int BruteForce::GetMinCost()
{
	return this->minCost;
}
int BruteForce::GetTotalTime()
{
	return this->totalTime;
}
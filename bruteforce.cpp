#include "bruteforce.hpp"

BruteForce::BruteForce(double** distances, int numElements)
{
	this->distances = distances;
	this->NUMELEMENTS = numElements;
	this->minCost = 99999;
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
	double weight = 0.00;

	for(int i = 0; i < NUMELEMENTS; ++i)
	{
		weight += distances[j][s[i]];
		j = s[i];
	}

	weight += distances[j][0];
	cout << "Current Perms Cost: " << weight << endl;
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
    cout << "\nARRAY Before: " << endl;
    cout << "---------" << endl;
    printS();
    Compute();

    for(i = 1; i < permsThisCall; i++)
    {
        t.SetEndTime();
		totalTime = t.GetTotalTime();
		if(totalTime >= MAXTIME)
		{
			cout << "Max Run-Time Exceeded! Terminating Brute Force Solution..." << endl;
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
       		cout << "\nARRAY After: " << endl;
   	 		cout << "---------" << endl;
    		printS();	
       		Compute();
       	}
    }
}
double BruteForce::GetMinCost()
{
	return this->minCost;
}
int BruteForce::GetTotalTime()
{
	return this->totalTime;
}
void BruteForce::printS()
{
	for(int i = 0; i < NUMELEMENTS; ++i)
	{
		cout << s[i] << ", ";
	}
	cout << endl;
}
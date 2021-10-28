#include "ga.hpp"

GeneticAlg::GeneticAlg(double** distances, int NUMELEMENTS, int initialSize, int numGenerations, int mutationPCT)
{
	this->distances = distances;
	this->initialSize = initialSize;
	this->NUMELEMENTS = NUMELEMENTS;
	this->numGenerations = numGenerations;
	this->mutationPCT = mutationPCT;
	this->generation = new int*[initialSize];

	

	FillFirstGeneration();
	GetCosts();
	for(int i = 1; i < numGenerations; ++i)
	{
		cout << "\nGENERATION " << i+1 << endl;
		cout << "----------------" << endl;
		cout << "Elite Route: ";
		for(int j = 0; j < NUMELEMENTS; ++j)
		{
			cout << generation[0][j] << ", ";
		}
		cout << endl;
		GetMutations();
	}

}
void GeneticAlg::GetMutations()
{
	int mutationRate = 100 / mutationPCT;
	int numMutations = initialSize / mutationRate;
	for(int k = 0; k < NUMELEMENTS; ++k)
	{
		s[k] = generation[0][k];
		cout << "S Array at " << k << ": " << s[k] << endl;
	}
	//cout << "NUMBER OF MUTATIONS PER GEN: " << numMutations << endl;
	for(int i = 0; i < numMutations; ++i)
	{
		for(int j = 0; j < NUMELEMENTS; ++j)
		{
			//generation[i+1][j] = generation[0][]
		}
	}
}
void GeneticAlg::FillFirstGeneration()
{
	for(int i = 0; i < NUMELEMENTS; ++i)
	{
		s[i] = i + 1;
	}
	generation[0] = new int[NUMELEMENTS];
    for(int j = 0; j < NUMELEMENTS; ++j)
    {
      	generation[0][j] = s[j];
      	//cout << "Generation at 0-" << " J-" << j << ": " << generation[0][j] << endl;
    }
	perm1(initialSize);
}
void GeneticAlg::GetCosts()
{
	double cost = 0.0;
	int x = 0;

	//int temp[NUMELEMENTS];
	for(int i = 0; i < initialSize; ++i)
	{
		for(int j = 0; j < NUMELEMENTS; ++j)
		{
			//cout << "TESTING***** " << endl;
			s[j] = generation[i][j];
			//cout << "TEMP AT  " << j << ": " << temp[j] << ", ";

		}
			cost = 0.0;
			x = 0;
			for(int k = 0; k < NUMELEMENTS; ++k)
			{
				cost += distances[x][s[k]];
				x = s[k];
			}
			cost += distances[x][0];
			//cout << "Cost: " << cost << endl;
			GetElite(cost);
			
	}
	
}
void GeneticAlg::GetElite(double cost)
{
	if(cost <= minCost)
	{
		int j = 0;
		minCost = cost;
		cout << "NEW ELITE FOUND. Cost: " << minCost << endl;
		cout  << "ELITE ROUTE: ";
		for(int i = 0; i < NUMELEMENTS; ++i)
		{
			generation[0][i] = s[i];
			j = s[i];
			cout << generation[0][i] << ", ";
		}
		cout << endl;
	}
	/*int j = 0;
	double weight = 0.00;

	for(int i = 0; i < NUMELEMENTS; ++i)
	{
		weight += distances[j][s[i]];
		j = s[i];
	}

	weight += distances[j][0];
	cout << "Current Perms Cost: " << weight << endl;
	if(weight <= minCost)
	{
		j = 0;
		minCost = weight;
		cout << "NEW ELITE FOUND. Cost: " << minCost << endl;
		cout  << "ELITE ROUTE: ";
		for(int i = 0; i < NUMELEMENTS; ++i)
		{
			generation[0][i] = s[i];
			j = s[i];
			cout << generation[0][i] << ", ";
		}
		cout << endl;
	}
	//minCost = min(minCost, weight);
*/
}
void GeneticAlg::swap(int m, int k)
{
	int temp = s[m];
	s[m] = s[k];
	s[k] = temp;
}
void GeneticAlg::perm1(int permsThisCall) 
{
	t.SetStartTime();
    int m, k, p , q, i;
    //cout << "\nARRAY Before: " << endl;
   // cout << "---------" << endl;
   // printS();
   // GetElite();
 


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
       	//cout << "\nARRAY After: " << endl;
       //	cout << "---------" << endl;
      	//printS();
      	generation[i] = new int[NUMELEMENTS];
      	for(int j = 0; j < NUMELEMENTS; ++j)
    	{
      		generation[i][j] = s[j];
      		//cout << "Generation at 0-" << " J-" << j << ": " << generation[i][j] << endl;
    	}
      	//GetElite();
       	}
    }
}
void GeneticAlg::printS()
{
	for(int i = 0; i < NUMELEMENTS; ++i)
	{
		cout << s[i] << ", ";
	}
	cout << endl;
}
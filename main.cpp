#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>
#include "bruteforce.hpp"
using namespace std;


static const int ARR_SIZE = 20;
double** distances = new double*[ARR_SIZE];
int Factorial(int n);
int GetDistances();
void RecordResults();

int main()
{

	GetDistances();
	int numCities;
	cout << "Enter the number of Cities to Run: ";
	cin >> numCities;
	int NUMELEMENTS = numCities - 1;

	int permsThisCall = Factorial(NUMELEMENTS);
	BruteForce b(distances, NUMELEMENTS);

	cout << "Perms This Call: " << permsThisCall << endl;

	//Exec Brute Force
	b.perm1(permsThisCall);
	int minCost = b.GetMinCost();
	cout << "\nMin Cost: " << minCost << endl;
	int totalTime = b.GetTotalTime(); //timeAfter - timeBefore;
	cout << "Total Run Time: " << totalTime << " seconds." << endl;

	


	return 0;
}

void RecordResults(int numCities, int minCost, int totalTime)
{
	ofstream outFS("results.csv");
	outFS << "No. of Cities," << "BF Optimal Cost," << "BF Run-Time,"
	<< "GA Optimal Cost," << "GA Run-Time," << "GA Pct of Optimal" << endl;
	outFS << numCities << "," << minCost << "," << totalTime << endl;

	outFS.close();
}

int Factorial(int n)
{
	int factorial = 1;
	for(int i = 1; i <= n; ++i)
	{
		factorial *= i;
	}
	return factorial;
}
int GetDistances()
{
	ifstream inFS;
	inFS.open("distances.txt");
	if(inFS.is_open())
	{
		for(int i = 0; i < ARR_SIZE; ++i)
		{
			distances[i] = new double[ARR_SIZE];
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
/*void PrintDistances()
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
}*/
/*void PrintDistances()
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
		cout << s[i] << ", ";
	}
}
/*void swap(int m, int k)
{
	int temp = s[m];
	//cout << "TEMP: " << temp << endl;
	s[m] = s[k];
	s[k] = temp;
}
void BruteForce()
{
	int j = 0;
	
	
	int weight = 0;
	//cout << "****LOOP START****" << endl;
	for(int i = 0; i < NUMELEMENTS; ++i)
	{
		//cout << "****TESTING****" << endl;
		weight += distances[j][s[i]];
		
		//cout << "Current WEIGHT: " << weight << endl;
		//cout << "Current MIN COST: " << minCost << endl;
		//cout << "S AT I: " << s[i] << endl; 
		j = s[i];
		//cout << "NEW MIN COST: " << minCost << endl;
	}
	//cout << "****LOOP END****" << endl;
	weight += distances[j][0];
	minCost = min(minCost, weight);
	//cout << "****FUNCTION END****" << endl;

}
void perm1(int permsThisCall) 
{
     int m, k, p , q, i;
     //cout << "\nARRAY Before: " << endl;
    // cout << "---------" << endl;
     //printS();
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
       //cout << "\nARRAY After: " << endl;
       //cout << "---------" << endl;
      //printS();
       //BRUTE FORCE APPROACH
       BruteForce();
     }
}*/
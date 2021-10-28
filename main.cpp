#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>
#include "bruteforce.hpp"
#include "filehandler.hpp"
#include "ga.hpp"
using namespace std;

int initialSize = 12;
int numGenerations = 2;
int mutationPCT = 25;

int Factorial(int n);
void PrintDistances(double** distances)
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

int main()
{
	string inputFileName = "distances.txt";
	string outputFileName = "results.csv";
	FileHandler f(inputFileName, outputFileName);
	double** distances = f.GetDistances();

	int numCities = 5;
	//cout << "Enter the number of Cities to Run: ";
	//cin >> numCities;
	int NUMELEMENTS = numCities - 1;
	int permsThisCall = Factorial(NUMELEMENTS);

	PrintDistances(distances);

	//EXEC GA
	cout << "-------------------------------------------------" << endl;
	cout << "|                Genetic Algorithm              |" << endl;
	cout << "-------------------------------------------------" << endl;
	GeneticAlg ga(distances, NUMELEMENTS, initialSize, numGenerations, mutationPCT);
//	ga.perm1(initialSize);

	//Exec Brute Force
	cout << "-------------------------------------------------" << endl;
	cout << "|                  Brute Force                  |" << endl;
	cout << "-------------------------------------------------" << endl;
	BruteForce b(distances, NUMELEMENTS);
	cout << "Perms This Call: " << permsThisCall << endl;

	
	b.perm1(permsThisCall);

	double minCost = b.GetMinCost();
	cout << "\nMin Cost: " << minCost << endl;
	int totalTime = b.GetTotalTime();
	cout << "Total Run Time: " << totalTime << " seconds." << endl;

	f.RecordResults(numCities, minCost, totalTime);

	return 0;
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

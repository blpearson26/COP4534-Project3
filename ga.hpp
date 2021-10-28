#ifndef GA_HPP
#define GA_HPP
#include <iostream>
#include <vector>
#include "timer.hpp"
using namespace std;

class GeneticAlg {

private:
	double** distances;
	int** generation;
	double minCost;
	int initialSize, NUMELEMENTS, numGenerations, mutationPCT, totalTime;
	static const int MAXTIME = 300;
	int* s;
	Timer t;

public:
	GeneticAlg(double** distances, int NUMELEMENTS, int initalSize, int numGenerations, int mutationPCT);
	void perm1(int permsThisCall);
	void swap(int m, int k);
	void FillFirstGeneration();
	void GetElite(double cost);
	void GetCosts();
	void GetMutations();
	void printS();


};

#endif
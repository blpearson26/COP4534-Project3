#ifndef BRUTEFORCE_HPP
#define BRUTEFORCE_HPP
#include <algorithm>
#include <iostream>
#include "timer.hpp"
using namespace std;

class BruteForce {

private:
	int minCost;
	int NUMELEMENTS;
	int totalTime;
	static const int MAXTIME = 500;
	double** distances;
	int* s;
	Timer t;

public:
	BruteForce(double** distances, int numElements);
	void Compute();
	void perm1(int permsThisCall);
	void swap(int m, int k);
	int GetMinCost();
	int GetTotalTime();

};

#endif
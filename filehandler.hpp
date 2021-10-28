#ifndef FILEHANDLER_HPP
#define FILEHANDLER_HPP
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class FileHandler {

private:
	ofstream outFS;
	ifstream inFS;
	string inFile, outFile;
	static const int ARR_SIZE = 20;
	double** distances = new double*[ARR_SIZE];

public:
	FileHandler(string inFile, string outFile);
	void RecordResults(int numCities, double minCost, int totalTime);
	double** GetDistances();


};

#endif
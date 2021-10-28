#include "filehandler.hpp"

FileHandler::FileHandler(string inFile, string outFile)
{
	this->inFile = inFile;
	this->outFile = outFile;
}
void FileHandler::RecordResults(int numCities, double minCost, int totalTime)
{
	inFS.open(outFile);
	if(inFS.is_open())
	{
		inFS.close();
		outFS.open(outFile, ios::app);
	}
	else
	{
	outFS.open(outFile);
	outFS << "  No. of,"  << "    BF," << "    BF,"
	<< "    GA," << "    GA," << "    GA " << endl;

	outFS << "   Cities," <<  "Min Cost," << "Run-Time," 
	<< "Min Cost," << "Run-Time," << "Optimal%" << endl;
	}

	outFS << numCities <<  "," << minCost << ","  
	<< "           "  << totalTime << "s." << endl;

	outFS.close();
}
double** FileHandler::GetDistances()
{
	ifstream inFS;
	inFS.open(inFile);
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
		return distances;
	}
	else
	{
		cout << "ERROR: Could not Open File! Closing Program..." << endl;
		exit(1);
	}
}
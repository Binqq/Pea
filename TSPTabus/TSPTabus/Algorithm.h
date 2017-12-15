#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <ctime>
#include <vector>
#include "Load.h"
using namespace std;

class Alg : public LoadTSP
{
public:
	vector<int> tabuList;
	vector<int> solution;
	vector<int> tmpsolution;
	vector<int>bestsolution;
	vector<int>bestsolution2;
	int tmpVert,tmpRand,tmpTabu,first,second;
	bool isInList;
	int cost,tmpCost,bestCost,newSol,bestCost2;
	
	void swapVertics(int size,int itr,int maxSize);
	void drawSolution(int size,int **tab,int itr,int maxSize);
};

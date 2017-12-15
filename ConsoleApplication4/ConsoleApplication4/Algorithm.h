#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "LoadFromATSP.h"
#ifndef Algorithm_hpp
#define Algorithm_hpp
using namespace std;
struct edgeAndMin
{
	int row;
	int column;
	int minimum;

};
struct dlistEl
{
	dlistEl * next;   // nastêpnik
	dlistEl * prev;   // poprzednik
	edgeAndMin data;
};
class dlist
{
public:
	dlistEl * head;  // pocz¹tek listy
	dlistEl * tail;  // koniec listy
	unsigned count;  // licznik elementów

	dlist();         // konstruktor
//	~dlist();        // destruktor
	void printl();
	void push_back(edgeAndMin data);
	void remove(dlistEl * e);
	void pop_front();
	void pop_back();
	dlistEl * max();
};
 struct vertics
{
public:
	int x;
	int y;
};
struct tableAndLimit
{
	int Limit;
	int **table;
	int Level;
	list<vertics> vert;
	int columnToDelete;
	int rowToDelete;
};

struct dListTabAndLim
{
	dListTabAndLim * next;   // nastêpnik
	dListTabAndLim * prev;
	tableAndLimit data;
};
class dList1
{
public:
	dListTabAndLim *head;
	dListTabAndLim *tail;
	unsigned count;

	dList1();
//	~dList1();
	//void prin(int Level, int L);
	void push_back(tableAndLimit data);
	void remove(dListTabAndLim * e);
	void pop_front();
	//void pop_back();
	dListTabAndLim * min();

};
class TSPAlgorithm : public LoadATSP
{
	int minRows, minColumn;// czy zrobiæ min jako tablice jedno wymiarowe?
	dlist listOfEdgeAndMin;
	dlistEl *max;
	int limitHelp;
	int rowToDelete, columnToDelete;
	list<vertics> vert;
public:	dList1 tableAndMin;
		int tmp, tmp1;
		tableAndLimit data;//nie wiem czy bedzie dobrze 

public:
	void SearchAndSubstractMinInRows(int Level, int **tab);
	void SearchAndSubstractMinInColumn(int Level, int **tab, int Limit);
	void SearchZeroAndMin(int Level, int **tab);
	void FindMaxCost(TSPAlgorithm file);
	void ChangeFullTable(int Level, TSPAlgorithm file, int Limit, int **tablica);
	void CreateNewTable(int Level, TSPAlgorithm file, int Limit, int **tablica);

};


#endif
//for (int i = 0; i < Level; i++)
//{
//	//tab[0][0] = NULL;
//	//int count1 = 0;
//	for (int j = 0; j < Level; j++)
//	{
//		
//		
//			if (i < rowToDelete && j < columnToDelete)
//			{
//				tabl[i][j] = tablica[i][j];
//			}
//			//count = rowToDelete;
//			if (tablica[i][0] == rowToDelete && tablica[0][j] == columnToDelete)
//			{
//				cout << setw(8);
//				tabl[i][j] = tablica[i + 1][j + 1];
//			}
//			else if (tablica[i][0] == rowToDelete)
//			{
//				count = i + 1;
//				cout << setw(8);
//				tabl[i][j] = tablica[count][j];

//			}
//			else if (j == 0 && i >= rowToDelete)
//			{
//				tabl[i][j] = tablica[(i + 1)][j];

//			}
//			else if (j == 0 && i <= rowToDelete)
//			{
//				tabl[i][j] = tablica[i][j];

//			}
//			else if (tablica[0][j] == columnToDelete)
//			{

//				cout << setw(8);
//				tabl[i][j] = tablica[i][(j + 1)];

//			}
//			else if (i == 0 && j >= columnToDelete)
//			{
//				tabl[i][j] = tablica[i][(j + 1)];

//			}
//			else if (i == 0)
//			{
//				tabl[0][j] = tablica[0][j];

//			}
//			
/*else
{
tab[i][j] = tablica[i][j];
}*/
/*if (tablica[i][0] == columnToDelete && tablica[0][j] == rowToDelete)
{
tabl[i][j] = 99999;

}

if (i > rowToDelete)
{
if (tablica[i+1][0] == columnToDelete && tablica[0][j] == rowToDelete)
{
tabl[i][j] = 99999;

}else
tabl[i][j] = tablica[i + 1][j];
}*/
/*	cout.width(7);
cout << tabl[i][j] << " ";
}
cout << endl;*/
//zmienna = tablica[2][0];



//for (int i = 0; i < Level; i++)
//{
//	if (count1 == rowToDelete)//max->data.column)
//	{
//		count1++;
//	}
//	int count = 0;
//	for (int j = 0; j < Level; j++)
//	{

//		if (count == rowToDelete && count1 == columnToDelete && rowToDelete != columnToDelete && Level>1)
//		{
//			count++;
//			tabl[i][j] = 9999;

//		}
//		else if (i == rowToDelete && j == columnToDelete)
//		{
//			count++;
//			tabl[i][j] = tablica[count1][count];
//			count++;
//		}
//		else if (i == rowToDelete)
//		{

//			tabl[i][j] = tablica[count1][count];
//			count++;
//		}
//		else if (j == columnToDelete)
//		{
//			count++;

//			tabl[i][j] = tablica[count1][count];

//			count++;
//		}
//		else
//		{


//			tabl[i][j] = tablica[count1][count];
//			count++;

//		}
#include "Algorithm.h"
#include "LoadFromATSP.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

int LoadATSP::**tab;

void TSPAlgorithm::SearchAndSubstractMinInRows(int Level, int **tab)
{
	minInRows = new int[Level];
	

	for (int i = 0; i < Level; i++)
	{
	 minRows = tab[0][0];
		for (int j = 0; j < Level; j++)
		{
			if (minRows > tab[i][j] && tab[i][j]<900)
			{

				minRows = tab[i][j];
			}
		}

		for (int j = 0; j < Level; j++)
		{
			if (minRows < 900)
			{
				tab[i][j] = tab[i][j] - minRows;
			}
		}
		if (minRows < 900)
		{
			minInRows[i] = minRows;//wczytanie do tablicy minimów
		}else
		{
			minInRows[i] = 0;
		}
	}
}

void TSPAlgorithm::SearchAndSubstractMinInColumn(int Level, int **tab, int Limit)
{
	cout << endl << endl;
	minInColumn = new int[Level];
 	for (int i = 0; i < Level; i++)
	{
		minColumn = tab[0][0];
		for (int j = 0; j < Level; j++)
		{
			//ara = tab[j][i];
			if (minColumn > tab[j][i] && tab[i][j]<900)
			{
				minColumn = tab[j][i];				
			}
		}
		for (int j = 0; j < Level; j++)
		{
			if (minColumn < 99999)
			{
				tab[j][i] = tab[j][i] - minColumn;
			}
		
		
		}
		if (minColumn < 900) {
			minInColumn[i] = minColumn;
		}
		else
		{
			minInColumn[i] = 0;

		}
			Limit += minInColumn[i] + minInRows[i];
		}
		data = { Limit,tab,Level};
	}

void TSPAlgorithm::SearchZeroAndMin(int Level, int **tab)
{
	//cout<<"--------" << Level <<"----------"<< endl;
	int col, ro;
	
	for (int i = 0; i < Level; i++)
	{
		int minRow = 99999, minColumn = 99999, minimum;
		for (int j = 0; j < Level; j++)
		{
			if (tab[i][j] == 0)
			{
				for (int z = 0; z < Level; z++)
				{
					col = tab[i][z];
					if (tab[i][z] < minRow && z != j)
					{
						minRow = tab[i][z];
					

					}
					if (tab[z][j] < minColumn && z != i)
					{
						minColumn = tab[z][j];
					}
				}
				minimum = minRow + minColumn;

				edgeAndMin element = { i,j,minimum };
				listOfEdgeAndMin.push_back(element);
				//tableAndLimit tabl ={limitHelp,}
			}

		}
	}
}

void TSPAlgorithm::FindMaxCost(TSPAlgorithm file)
{

	max = listOfEdgeAndMin.max();
	rowToDelete = max->data.row;
	columnToDelete = max->data.column;

	cout<<endl << "Usuwamy: " << rowToDelete << " i : " << columnToDelete << endl;
	
	while (listOfEdgeAndMin.count) listOfEdgeAndMin.pop_front();
	data.vert.push_back({ rowToDelete,columnToDelete });
	
	
	//cout << columnToDelete << endl << rowToDelete << endl << max << endl;
	//listOfEdgeAndMin.printl();
	

}

void TSPAlgorithm::ChangeFullTable(int Level, TSPAlgorithm file, int Limit, int **tablica)
{//Zrobiæ odawanie do listy
	cout << endl;
	cout << "Korzystam z tablicy: " << endl;
	for (int i = 0; i < Level; i++)
	{
		for (int j = 0; j < Level ; j++)
		{
			cout << setw(8);
			cout << tablica[i][j];
		}
		cout << endl;
	}
	for (int i = 0; i < Level; i++)
	{
		for (int j = 0; j < Level; j++)
		{
			if (j == columnToDelete && i == rowToDelete)
			{

				tablica[i][j] = 99999;

			}
				cout.width(4);
				cout << tablica[i][j] << " ";
		}
		cout << endl;
	}
	if (Level == 1 && tab[0][0] >= 9999)
	{

	}
	else
	{
	SearchAndSubstractMinInRows(Level, tablica);
	SearchAndSubstractMinInColumn(Level, tablica, Limit);
	SearchZeroAndMin(Level, tablica);
	FindMaxCost(file);
	tableAndMin.push_back(data);
	//cout<<endl << Limit << " Lmit, " << Level << " Level" << endl;
	//listOfTable.push_back(tab);
}
}
void TSPAlgorithm::CreateNewTable(int Level, TSPAlgorithm file, int Limit, int **tablica)
{//Zrobiæ dodawnie tego do list
	int **tabl;
	cout << "Korzystam z tablicy: " << endl;
	for (int i = 0; i < Level+1; i++)
	{
		for (int j = 0; j < Level+1; j++)
		{
			cout << setw(8);
			cout << tablica[i][j] ;
		}
		cout << endl;
	}
	tabl = new int *[Level];
	
	for (int i = 0; i < Level; i++)
	{
		tabl[i] = new int[Level];
	}

	int count1 = 0;
	for (int i = 0; i < Level; i++)
	{
		if (count1 == rowToDelete)//max->data.column)
		{
			count1++;
		}
		int count = 0;
		for (int j = 0; j < Level; j++)
		{

			if (count == rowToDelete && count1 == columnToDelete && rowToDelete!=columnToDelete && Level>1)
			{
				count++;
				tabl[i][j] = 9999;
				
			}
			else if(i == rowToDelete && j == columnToDelete)
			{ 
				count++;
				tabl[i][j] = tablica[count1][count];
				count++;
			}
			else if (i == rowToDelete)
			{
				
				tabl[i][j] = tablica[count1][count];
				count++;
			}
			else if (j == columnToDelete)
			{
				count++;
				
				tabl[i][j] = tablica[count1][count];
			
			count++;
			}
			else
			{
			
				
				tabl[i][j] = tablica[count1][count];
				count++;

			}
			//cout.width(4);
			//cout << tabl[i][j] << " ";

		}
		//bcout << endl<<endl;
		count1++;
	}
	//Level--;
	vertics vert1 = {rowToDelete,columnToDelete };
	//tableandlimit tabl = { limithelp,tabl,vert.push_back(vert1)};
	//listoftable.push_back(tabl);
	//listoftable.prin(level);
	//cout << endl << endl << endl;


	
		SearchAndSubstractMinInRows(Level, tabl);
		SearchAndSubstractMinInColumn(Level, tabl, Limit);
		SearchZeroAndMin(Level, tabl);
		FindMaxCost(file);
		tableAndMin.push_back(data);
	

}

dlist::dlist()
{
	head = tail = NULL;
	count = 0;
}

//dlist::~dlist()
//	while (count) pop_front();
//}

void dlist::push_back(edgeAndMin data)
{
	dlistEl * p;

	p = new dlistEl;
	p->data = data;
	p->next = NULL;
	p->prev = tail;
	tail = p;
	count++;
	if (p->prev) p->prev->next = p;
	else head = p;
}

void dlist::remove(dlistEl * e)//wierzcholki  i minima
{
	count--;
	if (e->prev) e->prev->next = e->next;
	else        head = e->next;
	if (e->next) e->next->prev = e->prev;
	else        tail = e->prev;
	delete e;
}

void dlist::pop_front()
{
	if (count) remove(head);
}

void dlist::pop_back()
{
	if (count) remove(tail);
}

dlistEl * dlist::max()
{
	dlistEl * p, *pmax;
	pmax = head;
	if (head)
		for (p = head->next; p; p = p->next)
			if (p->data.minimum > pmax->data.minimum)
			{
				pmax = p;
			}
	return pmax;
}
void dlist::printl()
{
	dlistEl * p;

	cout << setw(3) << count << " : ";
	p = head;
	while (p)
	{
		cout << p->data.row << " ; " << p->data.column << "wartosc: " << p->data.minimum << endl;
		p = p->next;
	}
	cout << endl;
}

dList1::dList1()
{
	head = tail = NULL;
	count = 0;
}
//
//dList1::~dList1()
//{
//	while (count) pop_front();
//}

void dList1::push_back(tableAndLimit data)
{
	dListTabAndLim *p;

	p = new dListTabAndLim;
	p->data = data;
	p->next = NULL;
	p->prev = tail;
	tail = p;
	count++;
	if (p->prev)
	{
		p->prev->next = p;
	}
	else head = p;
}

void dList1::remove(dListTabAndLim * e)//Tableandlimit
{
	count--;
	if (e->prev) e->prev->next = e->next;
	else        head = e->next;
	if (e->next) e->next->prev = e->prev;
	else        tail = e->prev;
	delete e;
}

void dList1::pop_front()
{
	if (count) remove(head);
}

dListTabAndLim * dList1::min()
{
	dListTabAndLim *p, *pmin;
	pmin = tail;
	if (tail)
		for (p = tail->prev; p; p = p->prev)
		{

			if (pmin->data.Limit > p->data.Limit)
			{
				pmin = p;
				//cout << "zmieniono" << endl;
			}
		}
	return pmin;
}

#include "Algorithm.h"

void Alg::swapVertics(int size, int itr, int maxSize)
{

	tabuList.resize(maxSize);
	tmpsolution = solution;
	vector<int>::iterator z;
	for (int i = 0; i<itr && i<size; i++)
	{
		for (int j = 0; j < itr && j<size; j++)
		{
			if (i != j)
			{
				tmpTabu = true;
				// sprawdzenie czy ruch znajduje siê w liœcie tabu
				for (z = tabuList.begin(); z != tabuList.end(); z++)
				{
					if (i == *z || j == *z)
					{
						if (z<tabuList.end() - 1)
							z++;
						if (j == *z || i == *z)
							tmpTabu = false;
						else tmpTabu = true;
					}
				}
				if (tmpTabu)
				{
					tmpsolution.at(i) = solution.at(j);
					tmpsolution.at(j) = solution.at(i);

					//zamiana  ostatniej œcie¿ki czyli tej powrotnej
					if (i == 0)
					{
						vector<int>::iterator tmpItr;
						tmpItr = tmpsolution.end();
						tmpItr--;
						tmpsolution.at(*tmpItr = tmpsolution.at(0));
					}
					// dodanie ruchu do listy tabu
					tmpCost = 0;
					for (int y = 0; y < size; y++)
					{
						tmpCost += tab[tmpsolution.at(y)][tmpsolution.at(y + 1)];
					}
					if (cost > tmpCost)
					{
						cost = tmpCost;
						tmpCost = 0;
						solution = tmpsolution;
						itr--;
					}
					tabuList.push_back(0);
					tabuList.push_back(1);
					tmpsolution = solution;
				}
			}

		}
	}

	cout << endl;
	vector<int>::iterator itr2;
	for (itr2 = tmpsolution.begin(); itr2 != tmpsolution.end(); itr2++)
	{
		cout << *itr2 << " - ";
	}
	cout << endl;
	cout << cost;
}

void Alg::drawSolution(int size, int **tab, int itr, int maxSize)
{
	//	srand((int)time(NULL));
	int b;
	isInList = false;
	cost = 0;

	for (int i = 0; i < size + 1; i++)
	{


		tmpVert = (rand() % size) + 1;
		b = tmpVert;
		if (solution.size() == 0)
		{
			solution.push_back(tmpVert);
		}
		vector<int>::iterator a;
		for (a = solution.begin(); a != solution.end(); a++)
		{

			if (*a == tmpVert)
			{
				isInList = false;
				break;
			}
			else isInList = true;

		}
		if (isInList)
		{
			solution.push_back(tmpVert);
			vector<int>::iterator d;
			d = solution.end();
			d--;
			int column = *d;
			d--;
			int row = *d;
			cost += tab[row][column];

		}
		else if (!isInList && solution.size() != 0 && solution.size()<size)
			i--;



	}
	if (solution.size() >= size)
	{
		vector<int>::iterator e;
		vector<int>::iterator f;

		f = solution.end();
		f--;
		int rows = *f;
		e = solution.begin();
		solution.push_back(*e);
		int col = *e;
		cost += tab[rows][col];
	}
	vector<int>::iterator c;
	for (c = solution.begin(); c != solution.end(); c++)
	{
		cout << *c << " - ";
	}
	cout << endl;
	cout << cost << endl;
	swapVertics(size, itr, maxSize);
}

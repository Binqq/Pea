#include "Algorithm.h"

void Alg::swapVertics(int size,int itr,int maxSize)
{

	
	int iteracja2=0;
	int iteracja3 = 0;
	tmpsolution = solution;
	vector<int>::iterator z;
	newSol = 2;
	bestCost = INT_MAX;
	first = 0;
	second = 1;
	//srand(time(NULL));
	for (int i = 0; i<size;i++)
	{
		for (int j = 0; j<size; j++)
		{
			if (i != j)
			{
				tmpTabu = true;
				// sprawdzenie czy ruch znajduje siê w liœcie tabu
				for (z = tabuList.begin(); z != tabuList.end(); z++)
				{
					if (i == *z || j == *z)
					{
						if(z<tabuList.end()-1)
							z++;
						if (j == *z || i == *z)
						{
							tmpTabu = false;
							break;
						}
						else tmpTabu = true;
					}
				}
				if (tmpTabu)
				{
					tmpsolution.at(i) = solution.at(j);
					tmpsolution.at(j) = solution.at(i);
					//tmpsolution.at(tmpsolution.back()) = tmpsolution.at(i);
					iteracja2++;//iteracja do sprawdzenie ile ju¿ zosta³o wykonancyh zamian bez polepsszenia
					iteracja3++;			//bo zerowane jest ni¿ej								
								//zamiana  ostatniej œcie¿ki czyli tej powrotnej
					if (i == 0||j==0)
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
					
					tabuList.push_back(i);
					tabuList.push_back(j);
					if (iteracja3 == maxSize)
					{
						tabuList.at(first) = INT_MAX;
						tabuList.at(second) = INT_MAX;
						first++;
						first++;
						second++;
						second++;
						iteracja3 = 0;
					}
					//*TODO critical event (jezeli przez iles zamian nie ma lepszego wyniku zmiana sciezki poczatkowej
					if (cost > tmpCost)
					{
						cost = tmpCost;
						tmpCost = 0;
						solution = tmpsolution;
						i = 0;
						j = 0;
						iteracja2 = 0;
						itr--;
					}
				
					tmpsolution = solution;
				}
			}
			if (iteracja2 >(itr/10) && newSol<size)
			{
				
				// zapamiêtanie najlepszego do tej pory wyniku
				if (cost < bestCost || newSol==2)
				{
					bestsolution = solution;
					bestCost = cost;
				}
		
				solution.clear();
				int b;
				isInList = false;
				cost = 0;
				int tmp = size;
				solution.push_back(tab[0][newSol]);
				int min, first, second;

				for (int i = newSol; i < size + 1; i, tmp--)
				{
					bool good;
					min = tab[i][i];
					for (int j = 1; j < size + 1; j++)
					{

						vector<int>::iterator itr1;
						for (itr1 = solution.begin(); itr1 != solution.end(); itr1++)
						{
							good = true;
							if (tab[0][j] == *itr1)
							{
								good = false;
								break;
							}
						}
						if (good == true)
						{
							if (i != j && min > tab[i][j])
							{
								min = tab[i][j];
								first = i;
								second = j;
							}
						}

					}

					if (tmp > 2)
					{
						solution.push_back(tab[0][second]);
						cost += min;
						i = second;
					}
					else if (tmp == 2)
					{
						solution.push_back(tab[0][second]);
						cost += min;
						vector<int>::iterator kl;
						kl = solution.begin();
						solution.push_back(*kl);
						cost += tab[second][*kl];
					}
					else if (tmp<2) break;
					
				}
				i = 0;
				j = 0;
				newSol++;
				iteracja2 = 0;
				tmpsolution = solution;
			}
			
		if (iteracja2 > (itr / 10) && newSol == size && bestCost < cost)
			{
				break;
				
			}
			if (itr == 0)
			{
				break;
		}
		}
		if (itr == 0)
		{
			break;
		}
		if (iteracja2 >(itr / 10) && newSol == size && bestCost < cost)
		{
			break;

		}
	}
	if (cost > bestCost)
	{
		solution = bestsolution;
		cost = bestCost;
	}
	cout << endl;
	vector<int>::iterator itr2;
	for (itr2 = solution.begin(); itr2 != solution.end(); itr2++)
	{
		cout << *itr2 << " - ";
	}
	cout << endl;
	cout << "Koszt przebycia sciezki: ";
	cout << cost << endl;;
}

void Alg::drawSolution(int size, int **tab, int itr, int maxSize)
{
	int b;
	isInList = false;
	cost = 0;
	int tmp = size;
	solution.push_back(tab[0][1]);
	int min, first, second;

	for (int i = 1; i < size + 1; i,tmp--)
	{
		bool good;
		min = tab[i][i];
		for (int j = 1; j < size + 1; j++)
		{
			
			vector<int>::iterator itr1;
			for (itr1 = solution.begin(); itr1 != solution.end(); itr1++)
			{
				good = true;
				if (tab[0][j] == *itr1)
				{
					good = false;
					break;
				}
			}
			if (good==true)
			{
				if (i != j && min > tab[i][j])
				{
					min = tab[i][j];
					first = i;
					second = j;
				}		
			}
		
		}
		
		if (tmp > 2)
		{
			solution.push_back(tab[0][second]);
			cost += min;
			i = second;
		}
		else if (tmp == 2)
		{
			solution.push_back(tab[0][second]);
				cost += min;
			vector<int>::iterator kl;
			kl = solution.begin();
			solution.push_back(*kl);
			cost += tab[second][1];
		}
		else if(tmp<2) break;
	}
	cout << "Poczatkowa sniezka: " << endl;
		vector<int>::iterator c;
		for (c = solution.begin(); c != solution.end(); c++)
		{
			cout << *c << " - ";
		}
		cout << endl;
		cout << "Koszt przebycia sciezki: ";
		cout << cost << endl;
		swapVertics(size,itr,maxSize);
	
}
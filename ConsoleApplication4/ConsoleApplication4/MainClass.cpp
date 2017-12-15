#include <iostream>
#include <fstream>
#include <string>
#include "LoadFromATSP.h"
#include "Algorithm.h"
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include "Czas.h"
using namespace std;


int main()
{
	//string name;
	fstream plik;
	Czas time;
	int tmp1,tmp2;
	string filename;
	TSPAlgorithm file;
	int **tab;
	//list<saves> save;
	dListTabAndLim *p,*d;
	int L = 0;// Limit
	cout << "Wprowadz nazwe pliku wraz z rozszerzeniem" << endl;
	cin >> filename;
	file.Load(plik, filename);
	tab = file.tab;//Pierwsz¹ tablicê te¿ trzeba dodaæ do listy
	time.czasStart();
	file.SearchAndSubstractMinInRows(file.Level, tab);
	file.SearchAndSubstractMinInColumn(file.Level, tab, L);
	file.SearchZeroAndMin(file.Level, tab);
	file.FindMaxCost(file);
	file.tableAndMin.push_back(file.data);
	p = file.tableAndMin.min();
	cout << endl << endl<< endl << endl;
	file.CreateNewTable(file.Level - 1, file, p->data.Limit, p->data.table);//Pierwsze dwie 
//cout << "rozmiar listy" << file.tableAndMin.count;
	//cout << "rozmiar listy" << file.tableAndMin.count;
	//file.FindMaxCost(file);
	file.SearchZeroAndMin(file.Level, tab);
	file.FindMaxCost(file);
	file.ChangeFullTable(file.Level, file, p->data.Limit, p->data.table);
	file.tableAndMin.remove(p);

	cout << file.tableAndMin.count << "Liczba wierzcholkow" << endl;
//	cout << d->data.table[1][0];
	

																			//file.ChangeFullTable(file.Level,p->data.table,file,p->data.Limit);//przeslac poprzednie ograniczenie
																			//p = file.tableAndMin.min();
																			//file.SearchAndSubstractMinInRows(p->data.Level, p->data.table);
																			//file.SearchAndSubstractMinInColumn(p->data.Level, p->data.table);
		//file.tableAndMin.remove(p);																/////////////////////////////////////
	int Limi;
	L = file.tableAndMin.min()->data.Level;
	while (L > 1)
	{
		/*cout << "Lista min" << endl;
		
			cout << setw(3);
			p = file.tableAndMin.head;
	
			cout << endl;*/
			p = file.tableAndMin.min();
			//Przeszukiwanie limitów
			cout << p->data.Limit;
			file.SearchZeroAndMin(p->data.Level, p->data.table);
			file.FindMaxCost(file);
			if (p->data.Limit <= file.tableAndMin.min()->data.Limit)
			{
				
				file.CreateNewTable(p->data.Level-1, file, p->data.Limit, p->data.table);
				
				d = file.tableAndMin.tail;
				if (d->data.Limit <= file.tableAndMin.min()->data.Limit && d->data.Level == 1)
				{
					/*file.SearchAndSubstractMinInRows(d->data.Level,d->data.table);
					file.SearchAndSubstractMinInColumn(d->data.Level, d->data.table, d->data.Limit);
					*/
					d->data.Limit += d->data.table[0][0];
					cout << "end" << endl;
					cout << d->data.Limit;
					time.pobierzCzas();
					int a = d->data.vert.size();
					break;
				}
				else
				{

					cout << file.tableAndMin.count << "Liczba wierzcholkow" << endl;
					file.SearchZeroAndMin(p->data.Level, p->data.table);
					file.FindMaxCost(file);
					file.ChangeFullTable(p->data.Level, file, p->data.Limit, p->data.table);
					//p->data.Level;

					L = p->data.Level; //file.tableAndMin.min()->data.Level;
					file.tableAndMin.remove(p);
					cout << file.tableAndMin.count << "Liczba wierzcholkow" << endl;
				}
			}
		
	}
	string a;
	cin >> a;
	return 0;
}
struct saves
{
	int x;
	int y;
};

struct dListSeves
{
	dListSeves * next;
	dListSeves * prev;
	saves data;
};
class dListSave
{
public:
	dListSeves *head;
	dListSeves *tail;
	unsigned count;

	//dListSave();
	void push_back(saves data)
	{
		dListSeves * p;

		p = new dListSeves;
		p->data = data;
		p->next = NULL;
		p->prev = tail;
		tail = p;
		count++;
		if (p->prev) p->prev->next = p;
		else head = p;
	}
	}
;



void Save(int row, int column,dListSave &listsave)
{

	saves rows;
	int d;
	d = listsave.count;
	if (d == NULL)
	{
		
		rows = { row,column };
		listsave.push_back(rows);
	}
	else
	{

	}



	
}

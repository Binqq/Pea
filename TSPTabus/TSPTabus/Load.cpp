#include "Load.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <math.h>
using namespace std;

void LoadTSP::Load(fstream & plik, string filename)
{
	string ala = "TYPE: TSP";
	string a, b = "NAME: ulysses16.tsp", c = "NAME: ulysses22.tsp";
	plik.open(filename, std::ios::in | std::ios::out);
	if (plik.good() == true)
	{
		std::cout << "Uzyskano dostep do pliku!" << std::endl;

		getline(plik, Name);
		getline(plik, Type);
		getline(plik, Comment);
		getline(plik, Dimension);
		if (Type == ala) getline(plik, a);
		getline(plik, Edge_w_type);
		if (Name == b || Name == c)
		{

		}
		else
		{
			getline(plik, Edge_w_format);
		}

		getline(plik, Edge_w_section);
		Dimension.erase(0, 10);
		Level = atoi(Dimension.c_str());
		cout << Level << endl;
		if (Type == ala)
		{
			CreateTable1(plik);
		}
		else {
			CreateTable(plik);
		}
	}
	else std::cout << "Nie udalo sie otowrzyc pliku" << std::endl;


}
void LoadTSP::CreateTable1(fstream & plik)
{
	int number;
	double ala = 9999;
	double deg, min, PI;
	double *latitude, *longitude, *x, *y;
	double RRR = 6378.388, q1, q2, q3, dij;
	x = new double[Level];
	y = new double[Level];
	latitude = new double[Level];
	longitude = new double[Level];
	for (int i = 0; i < Level; i++)
	{
		plik >> number;
		plik >> x[i];
		plik >> y[i];
		cout << x[i] << " " << y[i] << endl;
	}
	tab = new int *[Level + 1];
	for (int i = 0; i < Level + 1; i++)
	{
		tab[i] = new int[Level + 1];
	}
	for (int i = 0; i<Level; i++)
	{
		PI = 3.141592;
		deg = floor(x[i]);
		min = x[i] - deg;
		latitude[i] = PI * (deg + 5.0 * min / 3.0) / 180.0;
		deg = floor(y[i]);
		min = y[i] - deg;
		longitude[i] = PI * (deg + 5.0 * min / 3.0) / 180.0;

	}
	for (int i = 0; i < Level + 1; i++)
	{
		for (int j = 0; j < Level + 1; j++)
		{
			if (i == 0 && j == 0) tab[i][j] = NULL;
			if (i == 0)
			{
				cout << setw(8);
				tab[i][j] = j;
			}
			else if (j == 0)
			{
				cout << setw(8);
				tab[i][j] = i;
			}
		}
	}
	for (int i = 1; i < Level + 1; i++)
	{
		for (int j = 1; j < Level + 1; j++)
		{

			q1 = cos(longitude[i - 1] - longitude[j - 1]);
			q2 = cos(latitude[i - 1] - latitude[j - 1]);
			q3 = cos(latitude[i - 1] + latitude[j - 1]);
			dij = (int)(RRR * acos(0.5*((1.0 + q1)*q2 - (1.0 - q1)*q3)) + 1.0);

			if (i != j)
			{
				tab[i][j] = dij;
				//cout << setw(8);

			}
			else if (i == j)
			{


				tab[i][j] = 99999;

			}
			//	cout << tab[i][j];
		}
		cout << endl;
	}
	for (int i = 0; i < Level + 1; i++)
	{
		for (int j = 0; j < Level + 1; j++)
		{
			cout << setw(8);
			cout << tab[i][j];
		}
		cout << endl;
	}
}

void LoadTSP::CreateTable(fstream & plik)
{
	tab = new int *[Level + 1];
	for (int i = 0; i < Level + 1; i++)
	{
		tab[i] = new int[Level + 1];
	}
	for (int i = 0; i < Level + 1; i++)
	{

		for (int j = 0; j < Level + 1; j++)
		{
			if (i == 0 && j == 0) tab[i][j] = NULL;
			if (i == 0)
			{
				tab[i][j] = j;
			}
			else if (j == 0)
			{
				tab[i][j] = i
					;
			}
			else {
				plik >> tab[i][j];

			}
			if (i == j)
			{
				tab[i][j] = tab[1][1];
			}
			tab[0][0] = 0;
			cout << setw(4);
			cout << tab[i][j] << " ";
		}

		cout << endl;
	}




}



#include "LoadFromATSP.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <math.h>
using namespace std;

void LoadATSP::Load(fstream & plik, string filename)
{
	string ala = "TYPE: TSP";
	string a;
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
		getline(plik, Edge_w_format);
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
void LoadATSP::CreateTable1(fstream & plik)
{
	int number;
	int ala = 9999;
	double deg, min, PI;
	double *latitude, *longitude,*x, *y;
	double RRR = 6378.388, q1,q2,q3,dij;
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
	tab = new int *[Level];
	for (int i = 0; i < Level; i++)
	{
		tab[i] = new int[Level];
	}
	for(int i=0;i<Level;i++)
	{
		PI = 3.141592;
		deg = floor(x[i]);
		min = x[i] - deg;
		latitude[i] = PI * (deg + 5.0 * min / 3.0) / 180.0;
		deg = floor(y[i]);
		min = y[i] - deg;
		longitude[i] = PI * (deg + 5.0 * min / 3.0) / 180.0;

	}
	for (int i = 0; i < Level; i++)
	{
		for (int j = 0; j < Level; j++)
		{

			q1 = cos(longitude[i] - longitude[j]);
			q2 = cos(latitude[i] - latitude[j]);
			q3 = cos(latitude[i] + latitude[j]);
			dij = (int)(RRR * acos(0.5*((1.0 + q1)*q2 - (1.0 - q1)*q3)) + 1.0);
			if (i != j)
			{
				tab[i][j] = dij;
				cout << setw(10);
				cout << tab[i][j];
			}
			else if (i == j)
			{
			
				cout << setw(10);
				tab[i][j] = 99999;
				cout << tab[i][j];
			}
		}
		cout<<endl;
	}
}
	
void LoadATSP::CreateTable(fstream & plik)
{
	tab = new int *[Level];
	for (int i = 0; i < Level; i++)
	{
		tab[i] = new int[Level];
	}
	for (int i = 0; i < Level; i++)
	{
		for (int j = 0; j < Level; j++)
		{
			plik >> tab[i][j];
			cout << setw(4);
			cout << tab[i][j] << " ";
		}

		cout << endl;
	}




}



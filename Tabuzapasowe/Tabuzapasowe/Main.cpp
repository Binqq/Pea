#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>

#include "Load.h"
#include "Algorithm.h"
using namespace std;

int main()
{
	fstream plik;
	string filename;
	int itr;
	Alg file;
	int maxSize;
	cout << "Wprowadz nazwe pliku z problemem" << endl;
	cin >> filename;
	file.Load(plik, filename);
	cout << "Wprowadz liczbe iteracji" << endl;
	cin >> itr;
	cout << "Wprowadz okres kadencji dla ruchu w liscie tabu:" << endl;
	cin >> maxSize;
	file.drawSolution(file.Level, file.tab, itr, maxSize);
	cin >> filename;
	return 0;
}
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include "Czas.h"
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
	Czas time;
	fstream plik2;
	
		cout << "Wprowadz nazwe pliku z problemem" << endl;
		cin >> filename;
		file.Load(plik, filename);
			cout << "Wprowadz liczbe iteracji" << endl;
			cin >> itr;
			cout << "Wprowadz okres kadencji dla ruchu w liscie tabu:" << endl;
			cin >> maxSize;
		time.czasStart();
		file.drawSolution(file.Level, file.tab,itr ,maxSize		);
		time.pobierzCzas();
	
	cin >> filename;
	return 0;
}
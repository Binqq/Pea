#include "Czas.h"
#include "CzasFunkcja.h"
using namespace std;

void Czas::czasStart() {
	LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&li))
		cout << "B³¹d!\n";

	PCFreq = double(li.QuadPart) / 1000.0;

	QueryPerformanceCounter(&li);
	counter = li.QuadPart;
}



void Czas::pobierzCzas()
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	cout << (li.QuadPart - counter) / PCFreq << " milisekund" << endl;
	counter = 0;
}
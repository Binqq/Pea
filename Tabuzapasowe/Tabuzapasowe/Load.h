#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;
class LoadTSP
{
	string Name, Type, Comment, Edge_w_type, Edge_w_format, Edge_w_section, Dimension;

public:
	int **tab;
	int Level;

public:
	void Load(fstream & plik, string filename);
	void CreateTable(fstream & plik);
	void CreateTable1(fstream & plik);

};

#endif
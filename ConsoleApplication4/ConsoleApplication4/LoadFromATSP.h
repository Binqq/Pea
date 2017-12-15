#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#ifndef LoadFromATSP_hpp
#define LosdFromATSP_hpp
using namespace std;
class LoadATSP
{
	string Name, Type, Comment, Edge_w_type, Edge_w_format, Edge_w_section, Dimension;
public:	int Level;
public:
	int **tab;
	int *minInRows, *minInColumn; //minima
									 //list<int> limit;
public:
	void Load(fstream & plik, string filename);
	void CreateTable(fstream & plik);
	void CreateTable1(fstream & plik);

};

#endif
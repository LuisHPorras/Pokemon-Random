#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include "Constants.h"

using namespace std;

class Text_Manager
{
	ifstream file;
	const string name;
	string data[100][100];

public:
	Text_Manager(const string inName);
	~Text_Manager();

	bool find(const string w);
	void loadData(int Ln, int Col);
	string getData(int Ln, int Col) { return data[Ln][Col]; }
	string* getLine(int Ln) { return data[Ln]; }
	int getDataInt(int Ln, int Col) { return stoi(data[Ln][Col]); }
	Constants::Types getType(int Ln, int Col);
};


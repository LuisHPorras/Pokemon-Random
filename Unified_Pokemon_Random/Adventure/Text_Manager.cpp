#include "Text_Manager.h"



Text_Manager::Text_Manager(const string inName): name(inName)
{
	loadData(Constants::NUM_PKMN_DEX, Constants::NUM_STATS_DEX);
}


Text_Manager::~Text_Manager()
{
}

bool Text_Manager::find(const string w)
{
	string line;
	file.open(name, ios::in);

	if (file.is_open())
		while (getline(file, line))
		{
			if (!w.compare(line)) return true;//Si la palabra coincide devuelve verdadero		
		}

	else cout << "Error al abrir fichero\n";

	file.close();
	return false;
}

void Text_Manager::loadData(int Ln, int Col)
{
	string line;
	file.open(name, ios::in);

	if (file.is_open())
		for (int i = 0; i < Ln; i++)
		{
			getline(file, line);
			for (int j = 0; j < Col; j++)
				file >> data[i][j];
		}
	else cout << "Error al abrir fichero\n";

	file.close();
}

Constants::Types Text_Manager::getType(int Ln, int Col)
{
	int type = getDataInt(Ln, Col);
	if (type == 0)
		return Constants::FLYING;
	if (type == 1)
		return Constants::FIGHTING;
	if (type == 2)
		return Constants::ROCK;
}
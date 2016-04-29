#include "Pokemon.h"

using namespace std;

#pragma once
class Player: public Pokemon
{
	//GRAPHIC ELEMENTS
	Texture tmaxHp;
	Texture tcurrentHp;

	//GRAPHIC POSITIONING PARAMETERS
	Vector2D pmaxHp;
	Vector2D pcurrentHp;

	//DATA STRINGS
	string smaxHp;
	string scurrentHp;

	//ATTACKS
	Attack drill_peck;
public:
	//CONSTRUCTION - DESTRUCTION
	Player();
	~Player();

	//GRAPHIC METHODS
	bool loadFromFile(string pbody, string pground, string pdata, string tname);
	void render(int x, int y);
	void free();
	void updateXHealth();
};


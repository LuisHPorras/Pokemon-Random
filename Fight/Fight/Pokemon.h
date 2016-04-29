#include "Texture.h"
#include "Vector2D.h"
#include "Attack.h"

using namespace std;

#pragma once
class Pokemon
{
protected:
	//GRAPHIC ELEMENTS
	Texture body;
	Texture ground;
	Texture data;
	Texture name;
	Texture tLv;

	//GRAPHIC POSITIONING PARAMETERS
	Vector2D Health;
	Vector2D HP;
	Vector2D Name;
	Vector2D pLv;
	float groundMultiplier;

	//DATA STRINGS
	string sLv;

	//DYMENSIONS
	int width;
	int height;

	//STATS
	int maxHP;
	int currentHP;
	int Lv;
	int attack;
	int defence;
public:
	//CONSTRUCTION - DESTRUCTION
	Pokemon(int xHP=0, int yHP=0, int xName=0, int yName=0, int xLv=0, int yLv=0);
	~Pokemon();

	//MEDIA METHODS
	bool loadFromFile(string pbody, string pground, string pdata, string tname);
	void render(int x, int y);
	void free();

	//INTERFACE INLINE METHODS
	int getWidth(){return width;}
	int getHeight(){return height;}

	//FRINEDS
	friend class Healthbar;
};


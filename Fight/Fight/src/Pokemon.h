#pragma once

#include <string>
#include "Texture.h"
#include "Vector2D.h"
#include "Constants.h"
#include "ListOf.h"
#include "Attack.h"


extern SDL_Renderer* gRenderer;

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
	Vector2D posData;
	Vector2D HP;
	Vector2D pName;
	Vector2D pLv;
	float groundMultiplyer;

	//DATA STRINGS
	string sName;
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
	Constants::Types type;

	ListOf<Attack> attacks;
public:
	//CONSTRUCTION - DESTRUCTION
	Pokemon(int xHP = 0, int yHP = 0, int xName = 0, int yName = 0, int xLv = 0, int yLv = 0);
	~Pokemon(void);

	//MEDIA METHODS
	virtual bool loadFromFile(string pbody, string pground, string pdata);
	virtual void render(int x, int y);
	virtual void free();

	//INTERFACE INLINE METHODS
	int getWidth(){return width;}
	int getHeight(){return height;}
	int getCurrentHP(){return currentHP;}
};


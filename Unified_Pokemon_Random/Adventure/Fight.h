#pragma once

#include <SDL.h>
#include <iostream>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "Texture.h"
#include "Constants.h"
#include "Vector2D.h"
#include "ListOf.h"
#include "Pokemon.h"

using namespace std;

class Fight
{
	//SCENE
	Texture background;

	ListOf<Pokemon> pokemon;

	//STATE COORDINATION ATRIBUTES
	Vector2D cursor;
	Vector2D* option[4];
	enum States
	{

	}state;
public:
	//SCREEN DYMENSIONS
	static const int SCREEN_WIDTH = 800;
	static const int SCREEN_HEIGHT = 600;

	//CONSTRUCTION - DESTRUCTION
	Fight(void);
	~Fight(void);

	//START-STOP METHODS
	void close();

	//MEDIA METHODS
	bool loadMedia();
	void render();

	//EVENT MANAGEMENT
	void events(SDL_Event &e, bool &quit);
	void coordinateStates(SDL_Event &e);
};


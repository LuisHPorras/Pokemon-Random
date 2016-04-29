#include "Texture.h"
#include "Player.h"
#include "Enemy.h"
#include "Dialog.h"

#pragma once
class Fight
{
	//POKEMONS
	Player player;
	Enemy enemy;

	//SCENE
	Texture background;
	Dialog dialog;
public:
	//SCREEN DYMENSIONS
	static const int SCREEN_WIDTH = 800;
	static const int SCREEN_HEIGHT = 600;

	//CONSTRUCTION - DESTRUCTION
	Fight();
	~Fight();

	//START-STOP METHODS
	bool init();
	void close();

	//MEDIA METHODS
	bool loadMedia();
	void render();
	
	//EVENT MANAGEMENT
	void events(SDL_Event &e, bool &quit);
};


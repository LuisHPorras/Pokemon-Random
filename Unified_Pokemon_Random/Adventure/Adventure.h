#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "Constants.h"
#include "Texture.h"
#include "Map.h"
#include "Player_Trainer.h"

class Adventure
{
public:
	Adventure();
	~Adventure();

	void events(SDL_Event& e, bool& quit);
	void render();
	void close();
	bool loadFromFile();

	//Movable_Trainer *trainers[5];
	Player_Trainer player;
	Map route_0;

	//int previousKey;

};




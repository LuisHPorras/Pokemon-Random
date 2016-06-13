#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "Constants.h"
#include "Texture.h"
#include "Map.h"
#include "Player_Trainer.h"
#include "Movable_Trainer.h"

class Adventure
{
public:
	Adventure(): route_0(20, 20), sceneDim(13,11) {}
	~Adventure();

	bool loadFromFile();
	void events(SDL_Event& e, bool& quit);
	void render();
	void close();
	
//private:
	Orientation t[4] = { DOWN,UP,DOWN,UP };
	Vector2D cameraPos;
	Vector2D sceneDim;
	Map route_0;
	Player_Trainer player;
	Movable_Trainer *trainers[5];
};




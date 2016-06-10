#include "Adventure.h"

Adventure::Adventure()
{
}

Adventure::~Adventure()
{
}

void Adventure::events(SDL_Event& e, bool& quit)
{
	if (e.type == SDL_QUIT)
	{
		quit = true;
	}
	else if (e.type == SDL_KEYDOWN)
	{
		switch (e.key.keysym.sym)
		{
		case SDLK_UP:
			player.move(Constants::KEY_PRESS_DIRECTION_UP);
			//trainers[0]->move(KEY_PRESS_PLAYER_UP);
			//previousKey = Constants::KEY_PRESS_DIRECTION_UP;
			break;

		case SDLK_DOWN:
			player.move(Constants::KEY_PRESS_DIRECTION_DOWN);
			//trainers[0]->move(KEY_PRESS_PLAYER_DOWN);
			//previousKey = Constants::KEY_PRESS_DIRECTION_DOWN;
			break;

		case SDLK_LEFT:
			player.move(Constants::KEY_PRESS_DIRECTION_LEFT);
			//trainers[0]->move(KEY_PRESS_PLAYER_LEFT);
			//previousKey = Constants::KEY_PRESS_DIRECTION_LEFT;
			break;

		case SDLK_RIGHT:
			player.move(Constants::KEY_PRESS_DIRECTION_RIGHT);
			//trainers[0]->move(KEY_PRESS_PLAYER_RIGHT);
			//previousKey = Constants::KEY_PRESS_DIRECTION_RIGHT;
			break;

		default:
			break;
		}
	}
}

void Adventure::close()
{
	//Free loaded images
}

void Adventure::render()
{
	route_0.printMap();
	player.animate();
}

bool Adventure::loadFromFile()
{
	if (!player.loadFromFile())
		return false;
	
	return true;
}
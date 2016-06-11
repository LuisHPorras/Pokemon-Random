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

	camera.x = (player.getPos().x + Constants::PLAYER_WIDTH / 2 ) - Constants::SCREEN_WIDTH / 2;
	camera.y = (player.getPos().y + Constants::PLAYER_HEIGHT / 2) - Constants::SCREEN_HEIGHT / 2;

	//Keep the camera in bounds
	if (camera.x < 0)
	{
		camera.x = 0;
	}
	if (camera.y < 0)
	{
		camera.y = 0;
	}
	if (camera.x > Constants::LEVEL_WIDTH - camera.w)
	{
		camera.x = Constants::LEVEL_WIDTH - camera.w;
	}
	if (camera.y > Constants::LEVEL_HEIGHT - camera.h)
	{
		camera.y = Constants::LEVEL_HEIGHT - camera.h;
	}
}

void Adventure::close()
{
	//Free loaded images
}

void Adventure::render()
{
	//Render background
	route_0.printMap(0, 0, &camera);

	Vector2D rel_pos(player.getPos().x - camera.x, player.getPos().y - camera.y);
	player.animate();
}

bool Adventure::loadFromFile()
{
	if (!player.loadFromFile())
		return false;
	
	return true;
}
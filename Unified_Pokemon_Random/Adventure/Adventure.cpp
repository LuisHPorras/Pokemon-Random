#include "Adventure.h"

Adventure::~Adventure()
{
}

bool Adventure::loadFromFile()
{
	for (int i = 0; i < 5; i++)
	{
		trainers[i] = new Movable_Trainer(i, i);
		trainers[i]->loadFromFile();
		trainers[i]->setTrajectory(4, t);
	}

	route_0.loadFromFile();
	if (!player.loadFromFile())
		return false;

	return true;
}

void Adventure::events(SDL_Event& e, bool& quit)
{
	if (e.type == SDL_QUIT)
	{
		quit = true;
	}
	else if (e.type == SDL_KEYDOWN)
		switch (e.key.keysym.sym)
		{
		case SDLK_UP:
			player.move(Constants::KEY_PRESS_DIRECTION_UP);
			//trainers[0]->move(KEY_PRESS_PLAYER_UP);
			break;

		case SDLK_DOWN:
			player.move(Constants::KEY_PRESS_DIRECTION_DOWN);
			//trainers[0]->move(KEY_PRESS_PLAYER_DOWN);
			break;

		case SDLK_LEFT:
			player.move(Constants::KEY_PRESS_DIRECTION_LEFT);
			//trainers[0]->move(KEY_PRESS_PLAYER_LEFT);
			break;

		case SDLK_RIGHT:
			player.move(Constants::KEY_PRESS_DIRECTION_RIGHT);
			//trainers[0]->move(KEY_PRESS_PLAYER_RIGHT);
			break;

		default:
			break;
		}
	
	cameraPos = player.getPos() - (sceneDim/2);

	//Keep the camera in bounds
	if (cameraPos.x < 0)
		cameraPos.x = 0;
	
	if (cameraPos.y < 0)
		cameraPos.y = 0;
	
	if (cameraPos.x > route_0.getWidth() - sceneDim.x)
		cameraPos.x = route_0.getWidth();

	if (cameraPos.y > route_0.getHeight() - sceneDim.y)
		cameraPos.y = route_0.getHeight();

	player.setRelPos(cameraPos);

	/*for (int i = 0; i < 5; i++)
		trainers[i]->walk();*/
	
}

void Adventure::render()
{
	//Render background
	route_0.printSubMap(cameraPos.x, cameraPos.y, sceneDim.x, sceneDim.y);
	
	player.animate();
	for (int i = 0; i < 5; i++)
	{
		trainers[i]->walk();
		trainers[i]->animate();
	}
	
}

void Adventure::close()
{
	//Free loaded images
}



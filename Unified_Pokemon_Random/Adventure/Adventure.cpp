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
			player.move(UP);
			break;

		case SDLK_DOWN:
			player.move(DOWN);
			break;

		case SDLK_LEFT:
			player.move(LEFT);
			break;

		case SDLK_RIGHT:
			player.move(RIGHT);
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
		cameraPos.x = route_0.getWidth() - sceneDim.x;

	if (cameraPos.y > route_0.getHeight() - sceneDim.y)
		cameraPos.y = route_0.getHeight() - sceneDim.y;

	if (cameraPos.x != 0 && cameraPos.x != route_0.getWidth() - sceneDim.x && (e.key.keysym.sym  == SDLK_RIGHT || e.key.keysym.sym == SDLK_LEFT))
		player.setRelPos(cameraPos);

	if (cameraPos.y != 0 && cameraPos.y != route_0.getHeight() - sceneDim.y && (e.key.keysym.sym == SDLK_DOWN || e.key.keysym.sym == SDLK_UP))
		player.setRelPos(cameraPos);

	if ((cameraPos.x == route_0.getWidth() - sceneDim.x || cameraPos.x == 0) && (e.key.keysym.sym == SDLK_RIGHT || e.key.keysym.sym == SDLK_LEFT))
		player.Movable_Thing::setRelPos(cameraPos);

	if ((cameraPos.y == route_0.getHeight() - sceneDim.y || cameraPos.y == 0) && (e.key.keysym.sym == SDLK_DOWN || e.key.keysym.sym == SDLK_UP))
		player.Movable_Thing::setRelPos(cameraPos);
	//player.setRelPos(cameraPos);
}

void Adventure::render()
{
	
	//Render background
	route_0.printSubMap(cameraPos.x, cameraPos.y, sceneDim.x, sceneDim.y);
	
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < route_0.getNumLayers();j++)
		{
			if(i==0)
				Interaction::interaction(route_0.getLayer(j), &player);
			Interaction::interaction(route_0.getLayer(j), trainers[i]);
			trainers[i]->walk();
			trainers[i]->setRelPos(cameraPos);
			trainers[i]->animate();
		}

	player.animate();
}

void Adventure::close()
{
	//Free loaded images
}



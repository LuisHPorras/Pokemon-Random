#include "World.h"

World::World(): state(Constants::ADVENTURE)
{
}

World::~World()
{
}

bool World::init()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << endl;
		system("pause");
		return false;
	}

	if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		cout << "Warning: Linear texture filtering not enabled!" << endl;

	gWindow = SDL_CreateWindow("Pokemon Random", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	
	if (gWindow == NULL)
	{
		cout << "Window could not be created! SDL Error: " << SDL_GetError() << endl;
		system("pause");
		return false;
	}
	
	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (gRenderer == NULL)
	{
		cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << endl;
		system("pause");
		return false;
	}
	
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	int imgFlags = IMG_INIT_PNG;

	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;
		system("pause");
		return false;
	}

	if (TTF_Init() == -1)
	{
		cout << "SDL_ttf could not initialize! SDL_ttf Error: " << TTF_GetError() << endl;
		system("pause");
		return false;
	}
	
	gFont = TTF_OpenFont("Texturas/pokemon_ingame_bold.ttf", 28);

	if (gFont == NULL)
	{
		cout << "Failed to load image font! SDL_ttf Error: " << TTF_GetError() << endl;
		system("pause");
		return false;
	}
	
	return true;
}

bool World::loadMedia()
{
	if (!fight.loadMedia() || !adventure.loadFromFile())
		return false;

	return true;
}

void World::keyEvent(SDL_Event& e, bool& quit)
{
	switch (e.key.keysym.sym)
	{
	case SDLK_m:
		state = Constants::ADVENTURE;
		break;
	case SDLK_n:
		state = Constants::FIGHT;
		break;
	default:
		break;
	}

	if (state == Constants::FIGHT)
		fight.events(e, quit);
	if (state == Constants::ADVENTURE)
		adventure.events(e, quit);
}

void World::render()
{
	SDL_RenderClear(gRenderer);
	if (state == Constants::FIGHT)
		fight.render();
	if (state == Constants::ADVENTURE)
		adventure.render();
}

void World::close()
{
	//Destroy window	
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();

	//Free resources and close SDL
	adventure.close();
	fight.close();
}
#include "Fight.h"

//CONSTRUCTION - DESTRUCTION
Fight::Fight(void)
{
	int posOpt[8] = {100, 40, 475, 40, 100, 130, 475, 130};
	for (int i=0; i < 4; i++)
		option[i] = new Vector2D(posOpt[i*2], posOpt[i*2+1]);
	cursor = *option[0];
}


Fight::~Fight(void)
{
	for (int i=0; i < 4; i++)
		delete option[i];
}

//START-STOP METHODS
bool Fight::init()
{
	bool success = true;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout<<"SDL could not initialize! SDL Error: "<<SDL_GetError()<<endl;
		system("pause");
		success = false;
	}
	else
	{
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
			cout<<"Warning: Linear texture filtering not enabled!"<<endl;
		gWindow = SDL_CreateWindow("Pokemon Random", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			cout<<"Window could not be created! SDL Error: "<<SDL_GetError()<<endl;
			system("pause");
			success = false;
		}
		else
		{
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				cout<<"Renderer could not be created! SDL Error: "<<SDL_GetError()<<endl;
				system("pause");
				success = false;
			}
			else
			{
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					cout<<"SDL_image could not initialize! SDL_image Error: "<<IMG_GetError()<<endl;
					system("pause");
					success = false;
				}
				if (TTF_Init() == -1)
				{
					cout<<"SDL_ttf could not initialize! SDL_ttf Error: "<<TTF_GetError()<<endl;
					system("pause");
					success = false;
				}
				else
				{
					gFont = TTF_OpenFont("Texturas/pokemon_ingame_bold.ttf", 28);
					if (gFont == NULL)
					{
						cout<<"Failed to load image font! SDL_ttf Error: "<<TTF_GetError()<<endl;
						system("pause");
						success = false;
					}
				}
			}
		}
	}
	return success;
}

void Fight::close()
{
	//Free textures
	background.free();

	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	IMG_Quit();
	SDL_Quit();
}

//MEDIA METHODS
bool Fight::loadMedia()
{
	bool success = true;

	//Load textures
	if (!background.loadFromFile("Texturas/battle_background.png"))
	{
		cout<<"Failed to load background texture image!"<<endl;
		success = false;
	}

	return success;
}

void Fight::render()
{
	//Free textures
	background.free();

	loadMedia();

	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(gRenderer);

	//Render textures
	background.render(0, 0);

	SDL_RenderPresent(gRenderer);
}

//EVENT MANAGEMENT
void Fight::events(SDL_Event &e, bool &quit)
{
	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_QUIT)
			quit = true;
		else
		{
			//Write events
			coordinateStates(e);
		}
	}
}

void Fight::coordinateStates(SDL_Event &e)
{
}
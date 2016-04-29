#include "Fight.h"

using namespace std;

extern SDL_Window* gWindow;
extern SDL_Renderer* gRenderer;
extern TTF_Font* gFont;

//CONSTRUCTION - DESTRUCTION
Fight::Fight()
{
}


Fight::~Fight()
{
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
			std::cout<<"Window could not be created! SDL Error: "<<SDL_GetError()<<std::endl;
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
				}
				else
				{
					gFont = TTF_OpenFont("Texturas/pokemon_ingame_bold.ttf", 28);
					if (gFont == NULL)
					{
						cout<<"Failed to load ingame font! SDL_ttf Error: "<<TTF_GetError()<<endl;
						system ("pause");
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
	background.free();
	dialog.free();
	player.free();
	enemy.free();

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

	if (!background.loadFromFile("Texturas/battle_background.png"))
	{
		cout<<"Failed to load background texture image!"<<endl;
		success = false;
	}

	if (!dialog.loadFromFile("Texturas/menu3.png", "Texturas/ball_small.png"))
	{
		cout<<"Failed to load dialog texture image!"<<endl;
		success = false;
	}

	if (!player.loadFromFile("Texturas/dodrio_back.png", "Texturas/battle_base_wild_player.png", "Texturas/healthbar_player.png", "Dodrio"))
	{
		cout<<"Failed to load player texture image!"<<endl;
		success = false;
	}

	if (!enemy.loadFromFile("Texturas/golem_front.png", "Texturas/battle_base_wild_enemy.png", "Texturas/healthbar_enemy.png", "Golem"))
	{
		cout<<"Failed to load player texture image!"<<endl;
		success = false;
	}

	return success;
}

void Fight::render()
{
	background.free();
	dialog.free();
	player.free();
	enemy.free();

	loadMedia();


	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(gRenderer);

	background.render(0, 0);
	dialog.render(0, SCREEN_HEIGHT - dialog.getHeight());
	player.render(0, SCREEN_HEIGHT - dialog.getHeight() - player.getHeight());
	enemy.render(SCREEN_WIDTH - enemy.getWidth(), 0);

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
			dialog.events(e);
		}
	}
}
#include "Fight.h"

//CONSTRUCTION - DESTRUCTION
Fight::Fight(void)
{
	int posOpt[8] = {100, 40, 475, 40, 100, 130, 475, 130};
	for (int i=0; i < 4; i++)
		option[i] = new Vector2D(posOpt[i*2], posOpt[i*2+1]);
	cursor = *option[0];
	pokemon += new Player(0);
}


Fight::~Fight(void)
{
	for (int i=0; i < 4; i++)
		delete option[i];
}

//START-STOP METHODS
void Fight::close()
{
	//Free textures
	background.free();
	pokemon[0].free();
}

//MEDIA METHODS
bool Fight::loadMedia()
{
	bool success = true;

	//Load textures
	if (!background.loadFromFile("Texturas/battle_background.png"))
	{
		cout << "Failed to load background texture image!" << endl;
		success = false;
	}

	if (!pokemon[0].loadFromFile("Texturas/battle_base_wild_player.png", "Texturas/healthbar_player.png"))
	{
		cout << "Failed to load background texture image!" << endl;
		success = false;
	}

	return success;
}

void Fight::render()
{
	//Free textures
	//background.free();

	//loadMedia();

	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

	//Render textures
	background.render(0, 0);
	pokemon[0].render(0, 0);

}

//EVENT MANAGEMENT
void Fight::events(SDL_Event &e, bool &quit)
{
	if (e.type == SDL_QUIT)
		quit = true;
	else
	{
		//Write events
		coordinateStates(e);
	}
}

void Fight::coordinateStates(SDL_Event &e)
{
}
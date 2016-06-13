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
	pokemon.erase();
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
	loadStats();

	//Load textures
	if (!background.loadFromFile("Texturas/battle_background.png"))
	{
		cout << "Failed to load background texture image!" << endl;
		success = false;
	}

	for (int i = 0; i < pokemon.getNumber(); i++)
	if (!pokemon[i].loadFromFile())
	{
		cout << "Failed to load pokemon texture image!" << endl;
		success = false;
	}

	return success;
}

void Fight::render()
{
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

void Fight::loadStats()
{
	for (int i = 0; i < Constants::NUM_PKMN_STATE; i++)
	{
		if (info.getDataInt(i, 0) == 0)
			pokemon += new Player;
		if (info.getDataInt(i, 0) == 1)
			pokemon += new Enemy;
		pokemon[pokemon.getNumber() - 1].setData(info.getLine(i));
	}
}

Text_Manager Fight::info("data/State.txt", Constants::NUM_PKMN_STATE, Constants::NUM_STATS_STATE);
#include "Fight.h"

//CONSTRUCTION - DESTRUCTION
Fight::Fight(void)
	:dialog(option)
{
	int posOpt[8] = {100, 40, 475, 40, 100, 130, 475, 130};
	for (int i=0; i < 4; i++)
		option += new Vector2D(posOpt[i*2], posOpt[i*2+1]);
	cursor = option[0];
	state = Constants::MAIN;
}


Fight::~Fight(void)
{
	option.erase();
	pokemon.erase();
}

//START-STOP METHODS
void Fight::close()
{
	//Free textures
	background.free();
	pokemon[0].free();
	pokemon[1].free();
	dialog.free();
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

	if (!dialog.loadFromFile())
	{
		cout << "Failed to load dialog texture image!" << endl;
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
	dialog.render(0, Constants::SCREEN_HEIGHT - dialog.getHeight());
	pokemon[0].render(0, Constants::SCREEN_HEIGHT - dialog.getHeight() - pokemon[0].getHeight());
	pokemon[1].render(Constants::SCREEN_WIDTH - pokemon[1].getWidth(), 0);

	SDL_RenderPresent(gRenderer);
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
		dialog.events(state);
	}
}

void Fight::coordinateStates(SDL_Event &e)
{
}

void Fight::loadStats()
{
	int aux[Constants::NUM_STATS_STATE];
	for (int i = 0; i < Constants::NUM_PKMN_STATE; i++)
	{
		if (info.getDataInt(i, 0) == 0)
			pokemon += new Player;
		if (info.getDataInt(i, 0) == 1)
			pokemon += new Enemy;
		info.getLineInt(i, aux);
		pokemon[pokemon.getNumber() - 1].setData(aux);
	}
}

Text_Manager Fight::info("data/State.txt", Constants::NUM_PKMN_STATE, Constants::NUM_STATS_STATE);
#include "Pokemon.h"

//CONSTRUCTION - DESTRUCTION
Pokemon::Pokemon(int inDexNum, int xHP, int yHP, int xName, int yName, int xLv, int yLv):
	HP(xHP, yHP),
	pName(xName, yName),
	pLv(xLv, yLv),
	dexNum(inDexNum)
{
	width = 0;
	height = 0;
	sLv = to_string(Lv);
}


Pokemon::~Pokemon(void)
{
}

//MEDIA METHODS
bool Pokemon::loadFromFile(string pground, string pdata)
{
	bool success = true;
	loadStats(dexNum);

	if (!body.loadFromFile(pathBody))
	{
		cout<<"Failed to load body texture image!"<<endl;
		success = false;
	}

	if (!ground.loadFromFile(pground))
	{
		cout<<"Failed to load ground texture image!"<<endl;
		success = false;
	}

	if (!data.loadFromFile(pdata))
	{
		cout<<"Failed to load data texture image!"<<endl;
		success = false;
	}

	if (!name.loadFromRenderedText(sName))
	{
		cout<<"Failed to load name texture from text!"<<endl;
		success = false;
	}

	if (!tLv.loadFromRenderedText(sLv))
	{
		cout<<"Failed to load level texture from text!"<<endl;
		success = false;
	}

	width = ground.getWidth();
	height = body.getHeight();

	return success;
}

void Pokemon::render(int x, int y)
{
	//Pokemon render
	ground.render(x, (int)(y + height - ground.getHeight()/groundMultiplyer));
	body.render(x + width/2 - body.getWidth()/2, y);

	//Data render
	posData.y = y + 10;
	data.render(posData.x, posData.y);

	//Health render
	float relativeHP = (float) currentHP / maxHP;
	SDL_Rect hp = {posData.x + HP.x, posData.y + HP.y, (int)(144 * relativeHP), 9};
	SDL_SetRenderDrawColor(gRenderer, 0x00, 0xFF, 0x00, 0xFF);
	SDL_RenderFillRect(gRenderer, &hp);
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

	//Text render
	name.render(posData.x + pName.x, posData.y + pName.y);
	tLv.render(posData.x + pLv.x, posData.y + pLv.y);
}

void Pokemon::free()
{
	ground.free();
	body.free();
	data.free();
	name.free();
	tLv.free();
}

void Pokemon::loadStats(int index)
{
	//pokedex.getLine(dexNum);
	sName = pokedex.getData(index, 0);
	type = pokedex.getType(index, 1);
	maxHP = pokedex.getDataInt(index, 2);
	attack = pokedex.getDataInt(index, 3);
	defence = pokedex.getDataInt(index, 4);
	pathBody = pokedex.getData(index, 5);
}

Text_Manager Pokemon::pokedex("data/Pokedex.txt");
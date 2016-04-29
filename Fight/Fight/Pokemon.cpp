#include "Pokemon.h"

using namespace std;

extern SDL_Window* gWindow;
extern SDL_Renderer* gRenderer;
extern SDL_Color textColor;

//CONSTRUCTION - DESTRUCTION
Pokemon::Pokemon(int xHP, int yHP, int xName, int yName, int xLv, int yLv):
	HP(xHP, yHP),
	Name(xName, yName),
	pLv(xLv, yLv)
{
	width = 0;
	height = 0;
	Lv = 50;
	sLv = to_string(Lv);
}


Pokemon::~Pokemon()
{
}

//MEDIA METHODS
bool Pokemon::loadFromFile(string pbody, string pground, string pdata, string tname)
{
	bool success = true;

	if (!body.loadFromFile(pbody))
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

	if (!name.loadFromRenderedText(tname, textColor))
	{
		cout<<"Failed to render name texture!"<<endl;
		success = false;
	}

	if (!tLv.loadFromRenderedText(sLv, textColor))
	{
		cout<<"Failed to render level texture!"<<endl;
		success = false;
	}

	width = ground.getWidth();
	height = body.getHeight();

	return success;
}

void Pokemon::render(int x, int y)
{
	//Pokemon render
	ground.render(x, (int)(y + height - ground.getHeight()/groundMultiplier));
	body.render(x + width/2 - body.getWidth()/2, y);

	//Data render
	Health.y = y + 10;
	data.render(Health.x, Health.y);

	//Health render
	float relativeHP = (float)currentHP / maxHP;
	SDL_Rect hp = {Health.x + HP.x, Health.y + HP.y, (int)(144 * relativeHP), 9};
	SDL_SetRenderDrawColor(gRenderer, 0x00, 0xFF, 0x00, 0xFF);
	SDL_RenderFillRect(gRenderer, &hp);

	//Text render
	name.render(Health.x + Name.x, Health.y + Name.y);
	tLv.render(Health.x + pLv.x, Health.y + pLv.y);
}

void Pokemon::free()
{
	ground.free();
	body.free();
	data.free();
	name.free();
	tLv.free();
}
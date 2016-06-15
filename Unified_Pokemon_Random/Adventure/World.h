#pragma once

#include "Fight.h"
#include "Adventure.h"
#include "Constants.h"

using namespace std;

extern SDL_Window* gWindow;
extern SDL_Renderer* gRenderer;
extern TTF_Font* gFont;
extern SDL_Color textColor;

class World
{
public:
	World();
	~World();

	bool init();
	bool loadMedia();
	bool startScreen(SDL_Event& e, bool& quit);
	void keyEvent(SDL_Event& e, bool& quit);
	void render();
	void close();

private:
	Constants::State state; 

	Fight fight;
	Adventure adventure;

};

	

#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Textura.h"

extern SDL_Window* gWindow;
extern SDL_Renderer* gRenderer;

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

class Mundo
{

public:
	
	Mundo(void);
	~Mundo(void);

	bool init();
	void close();

private:

};


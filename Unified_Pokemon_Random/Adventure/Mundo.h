#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "Constants.h"
#include "Texture.h"

using namespace std;

extern SDL_Window* gWindow;
extern SDL_Renderer* gRenderer;
extern TTF_Font* gFont;
extern SDL_Color textColor;


extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

class Mundo
{

public:
	
	Mundo(void);
	~Mundo(void);

	bool inicializaSdl();
	bool inicializa();
	void close();

private:

};


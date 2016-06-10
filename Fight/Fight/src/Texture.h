#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "Constants.h"

using namespace std;

extern SDL_Renderer* gRenderer;
extern TTF_Font* gFont;
extern SDL_Color textColor;

class Texture
{
	//ATRIBUTES
	SDL_Texture* mTexture;
	int width;
	int height;
public:
	//CONSTRUCTION - DESTRUCTION
	Texture(void);
	~Texture(void);

	//GRAPHIC METHODS
	bool loadFromFile(string path);
	bool loadFromRenderedText(string textureText);
	void free();
	void render(int x, int y);

	//INTERFACE INLINE METHODS
	int getWidth(){return width;}
	int getHeight(){return height;}
};


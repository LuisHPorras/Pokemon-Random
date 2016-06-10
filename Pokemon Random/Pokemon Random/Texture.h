#pragma once

#include <iostream>
#include <string>
#include "Mundo.h"

extern SDL_Window* gWindow;
extern SDL_Renderer* gRenderer;

class Texture
{
public:
	Texture();
	~Texture();

	int getWidth();
	int getHeight();

	void setColor(Uint8 red, Uint8 green, Uint8 blue);
	void setBlendMode(SDL_BlendMode blending);
	void setAlpha(Uint8 alpha);
	
	bool loadFromFile(std::string path);
	void render(int x, int y, SDL_Rect* clip);
	void render(int x, int y);

private:
	SDL_Texture* sdlTexture;
	int width;
	int height;
	
	void free();

friend class Mundo;
};


#pragma once

#include <iostream>
#include <string>
#include "Mundo.h"

using namespace std;

extern SDL_Window* gWindow;
extern SDL_Renderer* gRenderer;

class Texture
{
public:
	Texture();
	~Texture();

	int getWidth() { return width; }
	int getHeight() { return height; }

	void setColor(Uint8 red, Uint8 green, Uint8 blue);
	void setBlendMode(SDL_BlendMode blending);
	void setAlpha(Uint8 alpha);
	
	bool loadFromFile(string path);
	bool loadFromRenderedText(string textureText);
	void render(int x, int y, SDL_Rect* clip);
	void render(int x, int y);
	void free();


private:
	SDL_Texture* sdlTexture;
	int width;
	int height;

friend class Mundo;
};


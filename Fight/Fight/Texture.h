#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

#pragma once
class Texture
{
	//ATRIBUTES
	SDL_Texture* mTexture;
	int width;
	int height;
public:
	//CONSTRUCTION - DESTRUCTION
	Texture();
	~Texture();

	//GRAPHIC METHODS
	bool loadFromFile(string path);
	bool loadFromRenderedText(string textureText, SDL_Color textColor);
	void free();
	void render(int x,int y);

	//INTERFACE INLINE METHODS
	int getWidth(){return width;}
	int getHeight(){return height;}
};


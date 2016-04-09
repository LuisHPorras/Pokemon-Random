#pragma once
#include <iostream>
#include <string>
#include "Mundo.h"

extern SDL_Window* gWindow;
extern SDL_Renderer* gRenderer;

class Textura
{
public:
	Textura();
	~Textura();

	int getWidth();
	int getHeight();

	void setColor(Uint8 red, Uint8 green, Uint8 blue);
	void setBlendMode(SDL_BlendMode blending);
	void setAlpha(Uint8 alpha);
	
	
	bool cargarDesdeArchivo(std::string path);
	bool spritHorizontal(SDL_Rect *gSpriteClips, std::string path);
	void renderizar(int x, int y, SDL_Rect* clip=NULL);

private:
	//The actual hardware texture
	SDL_Texture* mTexture;

	//Image dimensions
	int width;
	int height;

	//Loads image at specified path
	
	void free();

friend class Mundo;
};


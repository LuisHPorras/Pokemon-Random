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
	void renderizar(int x, int y, SDL_Rect* clip);
	void renderizar(int x, int y);

private:
	//Textura en SDL
	SDL_Texture* sdlTexture;

	//Dimensiones de la imagen
	int width;
	int height;
	
	void free();

friend class Mundo;
};


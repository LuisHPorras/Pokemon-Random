#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Constantes.h"
#include "Vector2D.h"
#include "Textura.h"

class Animacion
{
public:
	
	Textura textura;
	SDL_Rect clips[FRAME_TOTAL];

	//Renderiza la animacion
	void renderizar(Vector2D posicion, bool movement);

	Animacion(void);
	~Animacion(void);

private:
	int frame;
};


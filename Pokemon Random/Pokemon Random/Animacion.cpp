#include "Animacion.h"

Animacion::Animacion(void)
{
	frame = 0;
}

Animacion::~Animacion(void)
{
}

void Animacion::renderizar(Vector2D posicion, bool movement)
{
	if(movement)
	{
		SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
		//SDL_RenderClear(gRenderer);

		//Render current frame
		SDL_Rect* currentClip = &clips[frame / (FRAMES_RATE / 2)];
		textura.renderizar(((SCREEN_WIDTH - currentClip->w) / 2) + (posicion.x / FRAMES_RATE), ((SCREEN_HEIGHT - currentClip->h) / 2)  + (posicion.y / FRAMES_RATE), currentClip);

		//Go to next frame
		++frame;

		//Cycle animation
		if (frame / (FRAMES_RATE / 2) >= FRAME_TOTAL)
		{
			frame = 0;
		}
	}
	else
	{
		frame = 0;

		SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
		//SDL_RenderClear(gRenderer);

		//Render current frame
		SDL_Rect* clip = &clips[FRAME_DEFAULT];
		textura.renderizar(((SCREEN_WIDTH - clip->w) / 2) + (posicion.x / FRAMES_RATE), ((SCREEN_HEIGHT - clip->h) / 2)  + (posicion.y / FRAMES_RATE), clip);
	}

}

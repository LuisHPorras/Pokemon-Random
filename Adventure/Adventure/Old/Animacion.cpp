#include "Animacion.h"

Animacion::Animacion(void)
{
	frame = 0;
}

Animacion::~Animacion(void)
{
}

bool Animacion::spritHorizontal(SDL_Rect *gSpriteClips, std::string path)
{
	//Loading success flag
	bool success = true;

	//Load sprite sheet texture
	if (!textura.cargarDesdeArchivo(path.c_str()))
	{
		printf("Failed to load walking animation texture!\n");
		system("PAUSE");
		success = false;
	}
	else
	{
		//Set sprite clips
		(gSpriteClips + 0)->x = 0;
		(gSpriteClips + 0)->y = 0;
		(gSpriteClips + 0)->w = 64;
		(gSpriteClips + 0)->h = 64;
	
		(gSpriteClips + 1)->x = 0;
		(gSpriteClips + 1)->y = 0;
		(gSpriteClips + 1)->w = 64;
		(gSpriteClips + 1)->h = 64;
		
		(gSpriteClips + 2)->x = 64;
		(gSpriteClips + 2)->y = 0;
		(gSpriteClips + 2)->w = 64;
		(gSpriteClips + 2)->h = 64;

		(gSpriteClips + 3)->x = 128;
		(gSpriteClips + 3)->y = 0;
		(gSpriteClips + 3)->w = 64;
		(gSpriteClips + 3)->h = 64;
		
		(gSpriteClips + 4)->x = 128;
		(gSpriteClips + 4)->y = 0;
		(gSpriteClips + 4)->w = 64;
		(gSpriteClips + 4)->h = 64;
		
		(gSpriteClips + 5)->x = 64;
		(gSpriteClips + 5)->y = 0;
		(gSpriteClips + 5)->w = 64;
		(gSpriteClips + 5)->h = 64;
	}

	return success;
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

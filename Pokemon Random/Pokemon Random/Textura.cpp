#include "Textura.h"

Textura::Textura()
{
	//Initialize
	sdlTexture = NULL;
	width = 0;
	height = 0;
}

Textura::~Textura()
{
	//Deallocate
	free();
}

int Textura::getWidth()
{
	return width;
}

int Textura::getHeight()
{
	return height;
}

void Textura::setColor(Uint8 red, Uint8 green, Uint8 blue)
{
	//Modulate texture rgb
	SDL_SetTextureColorMod(sdlTexture, red, green, blue);
}

void Textura::setBlendMode(SDL_BlendMode blending)
{
	//Set blending function
	SDL_SetTextureBlendMode(sdlTexture, blending);
}

void Textura::setAlpha(Uint8 alpha)
{
	//Modulate texture alpha
	SDL_SetTextureAlphaMod(sdlTexture, alpha);
}

bool Textura::cargarDesdeArchivo( std::string path)
{
	//Get rid of preexisting texture
	free();

	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Color key image
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		else
		{
			//Get image dimensions
			width = loadedSurface->w;
			height = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	//Return success
	sdlTexture = newTexture;
	return sdlTexture != NULL;
}

void Textura::renderizar(int x, int y, SDL_Rect* clip)
{
	//Set clip rendering dimensions
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, (clip->w) - 40, (clip->h) - 40 };
	
	SDL_RenderCopy(gRenderer, sdlTexture, clip, &renderQuad);
}

void Textura::renderizar(int x, int y)
{
	SDL_RenderCopy(gRenderer, sdlTexture, NULL, NULL);
}

void Textura::free()
{
	//Free texture if it exists
	if (sdlTexture != NULL)
	{
		SDL_DestroyTexture(sdlTexture);
		sdlTexture = NULL;
		width = 0;
		height = 0;
	}
}


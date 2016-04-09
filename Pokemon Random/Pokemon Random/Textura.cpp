#include "Textura.h"


Textura::Textura()
{
	//Initialize
	mTexture = NULL;
	width = 0;
	height = 0;
}

Textura::~Textura()
{
	//Deallocate
	free();
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
	mTexture = newTexture;
	return mTexture != NULL;
}

bool Textura::spritHorizontal(SDL_Rect *gSpriteClips, std::string path)
{
	//Loading success flag
	bool success = true;

	//Load sprite sheet texture
	if (!cargarDesdeArchivo(path.c_str()))
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

void Textura::renderizar(int x, int y, SDL_Rect* clip)
{
	//Set clip rendering dimensions
	if (clip != NULL)
	{
		//Set rendering space and render to screen
		SDL_Rect renderQuad = { x, y, width, height };

		renderQuad.x = x;
		renderQuad.y = y;
		renderQuad.w = clip->w - 40;
		renderQuad.h = clip->h - 40;
		
		SDL_RenderCopy(gRenderer, mTexture, clip, &renderQuad);
	}
	else	SDL_RenderCopy(gRenderer, mTexture, NULL, NULL);

}


void Textura::free()
{
	//Free texture if it exists
	if (mTexture != NULL)
	{
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		width = 0;
		height = 0;
	}
}

void Textura::setColor(Uint8 red, Uint8 green, Uint8 blue)
{
	//Modulate texture rgb
	SDL_SetTextureColorMod(mTexture, red, green, blue);
}

void Textura::setBlendMode(SDL_BlendMode blending)
{
	//Set blending function
	SDL_SetTextureBlendMode(mTexture, blending);
}

void Textura::setAlpha(Uint8 alpha)
{
	//Modulate texture alpha
	SDL_SetTextureAlphaMod(mTexture, alpha);
}

int Textura::getWidth()
{
	return width;
}

int Textura::getHeight()
{
	return height;
}
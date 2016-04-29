#include "Texture.h"

using namespace std;

extern SDL_Window* gWindow;
extern SDL_Renderer* gRenderer;
extern TTF_Font* gFont;

//CONSTRUCTION - DESTRUCTION
Texture::Texture()
{
	mTexture = NULL;
	width = 0;
	height = 0;
}


Texture::~Texture()
{
	free();
}

//GRAPHIC METHODS
bool Texture::loadFromFile(string path)
{
	free();
	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		cout<<"Unable to load image "<<path.c_str()<<"! SDL_Image Error: "<<IMG_GetError()<<endl;
		system("pause");
	}
	else
	{
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			cout<<"Unable to create texture from "<<path.c_str()<<"! SDL Error: "<<SDL_GetError()<<endl;
			system("pause");
		}
		else
		{
			width = loadedSurface->w;
			height = loadedSurface->h;
		}
		SDL_FreeSurface(loadedSurface);
	}
	mTexture = newTexture;
	return mTexture != NULL;
}

bool Texture::loadFromRenderedText(string textureText, SDL_Color textColor)
{
	free();
	SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, textureText.c_str(), textColor);
	if (textSurface == NULL)
	{
		cout<<"Unable to render text surface! SDL_ttf Error: "<<TTF_GetError()<<endl;
		system ("pause");
	}
	else
	{
		mTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
		if (mTexture == NULL)
		{
			cout<<"Unable to create texture from rendered text! SDL Error: "<<SDL_GetError()<<endl;
			system ("pause");
		}
		else
		{
			width = textSurface->w;
			height = textSurface->h;
		}
		SDL_FreeSurface(textSurface);
	}
	return mTexture != NULL;
}

void Texture::free()
{
	if (mTexture != NULL)
	{
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		width = 0;
		height = 0;
	}
}

void Texture::render(int x, int y)
{
	SDL_Rect renderQuad = {x, y, width, height};
	SDL_RenderCopy(gRenderer, mTexture, NULL, &renderQuad);
}
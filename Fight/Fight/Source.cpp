#include <SDL.h>
#include <SDL_ttf.h>
#include "src\Fight.h"

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
TTF_Font* gFont = NULL;
SDL_Color textColor = {0x5A, 0x5A, 0x5A};

Fight fight;

int main(int argc, char* args[])
{
	if (!fight.init())
		cout<<"Failed to initialize!"<<endl;
	else
	{
		if (!fight.loadMedia())
			cout<<"Failed to load media!"<<endl;
		else
		{
			bool quit = false;
			SDL_Event e;
			while (!quit)
			{
				fight.events(e, quit);
				fight.render();
			}
		}
	}
	fight.close();
	return 0;
}
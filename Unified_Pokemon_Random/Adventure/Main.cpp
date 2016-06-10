#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include "Constants.h"
#include "Mundo.h"
#include "Texture.h"
#include "Animation.h"
#include "Movable_Trainer.h"
#include "Player_Trainer.h"
#include "Map.h"

//using namespace std;

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

TTF_Font* gFont = NULL;
SDL_Color textColor = { 0x5A, 0x5A, 0x5A };


int previousKey;
bool quit;

Mundo mundo;

int main(int argc, char* args[])
{
	

	//Start up SDL and create window
	if (!mundo.inicializaSdl())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Main loop flag
		bool quit = false;

		//Event handler
		SDL_Event e;
		
		//Movable_Trainer *trainers[5];
		Player_Trainer player;

		Map route_0;

		/*Texture background;

		background.loadFromFile("Zona_Safari.png");*/

		//While application is running
		while (!quit)
		{
			SDL_RenderClear(gRenderer);
			route_0.printMap();
			//background.render((SCREEN_WIDTH - background.getWidth()) / 2, (SCREEN_HEIGHT - background.getHeight()) / 2);
			
			//Handle events on queue
			if (SDL_PollEvent(&e) != 0)
			{
				//User requests quit
				if (e.type == SDL_QUIT)
				{
					quit = true;
				}
				else if( e.type == SDL_KEYDOWN )
				{
					//Select surfaces based on key press
					switch( e.key.keysym.sym )
					{
						case SDLK_UP:
						player.move(Constants::KEY_PRESS_DIRECTION_UP);
						//trainers[0]->move(KEY_PRESS_PLAYER_UP);
						previousKey = Constants::KEY_PRESS_DIRECTION_UP;
						break;

						case SDLK_DOWN:
						player.move(Constants::KEY_PRESS_DIRECTION_DOWN);
						//trainers[0]->move(KEY_PRESS_PLAYER_DOWN);
						previousKey = Constants::KEY_PRESS_DIRECTION_DOWN;
						break;

						case SDLK_LEFT:
						player.move(Constants::KEY_PRESS_DIRECTION_LEFT);
						//trainers[0]->move(KEY_PRESS_PLAYER_LEFT);
						previousKey = Constants::KEY_PRESS_DIRECTION_LEFT;
						break;

						case SDLK_RIGHT:
						player.move(Constants::KEY_PRESS_DIRECTION_RIGHT);
						//trainers[0]->move(KEY_PRESS_PLAYER_RIGHT);
						previousKey = Constants::KEY_PRESS_DIRECTION_RIGHT;
						break;

						default:
						break;
					}
				}
			}
			player.animate();
			//trainers[0]->animate();

			//Update screen
			SDL_RenderPresent(gRenderer);
		}
	}

	//Free resources and close SDL
	mundo.close();

	return 0;
}
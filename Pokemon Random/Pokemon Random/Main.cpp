#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include "Constantes.h"
#include "Mundo.h"
#include "Texture.h"
#include "Animation.h"
#include "Player_Trainer.h"


//using namespace std;


//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

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
		
		Jugador jugador;
		Textura fondo;

		fondo.cargarDesdeArchivo("Zona_Safari.png");

		//While application is running
		while (!quit)
		{
			//Handle events on queue
			while (SDL_PollEvent(&e) != 0)
			{
				SDL_RenderClear(gRenderer);
				
				fondo.renderizar((SCREEN_WIDTH - fondo.getWidth()) / 2, (SCREEN_HEIGHT - fondo.getHeight()) / 2);
				
				//User requests quit
				if (e.type == SDL_QUIT)
				{
					quit = true;
				}
				else if( e.type == SDL_KEYDOWN )
					{
						
						//SDL_RenderClear(gRenderer);
						//Select surfaces based on key press
						switch( e.key.keysym.sym )
						{
							case SDLK_UP:
							jugador.mover(KEY_PRESS_PLAYER_UP);
							previousKey = KEY_PRESS_PLAYER_UP;
							break;

							case SDLK_DOWN:
							jugador.mover(KEY_PRESS_PLAYER_DOWN);
							previousKey = KEY_PRESS_PLAYER_DOWN;
							break;

							case SDLK_LEFT:
							jugador.mover(KEY_PRESS_PLAYER_LEFT);
							previousKey = KEY_PRESS_PLAYER_LEFT;
							break;

							case SDLK_RIGHT:
							jugador.mover(KEY_PRESS_PLAYER_RIGHT);
							previousKey = KEY_PRESS_PLAYER_RIGHT;
							break;

							default:
							break;
						}
					}
				else jugador.reposo(previousKey);

				//Update screen
				SDL_RenderPresent(gRenderer);
			}
		}
	}

	//Free resources and close SDL
	mundo.close();

	return 0;
}
#pragma once

#include <SDL.h>
#include <SDL_ttf.h>

class Constants
{
public:
	static enum Types{
		Flying,
		Fighting,
		Rock
	};
	Constants(void);
	~Constants(void);
	static void init();
};


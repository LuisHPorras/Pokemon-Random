#pragma once

#include <SDL.h>
#include "Vector2D.h"
#include "Timer.h"
#include "Texture.h"

class Animation
{
public:

	Animation(void);
	~Animation(void);

	void loadSprite(std::string path);
	void setClips(int inFrames, int *xvec, int *yvec, int *wvec, int *hvec);
	void setSequence(int dim, int *inSequence, int *inTimeInterval);
	void setSpaceInterval(Vector2D inStartPosition, Vector2D inEndPosition);
	bool isEnded();
	void start();
	void animate();
	void hold();

private:

	Texture texture;
	SDL_Rect* clips;
	SDL_Rect* currentClip;
	Timer timer;
	Vector2D startPosition, endPosition;
	Vector2D spaceInterval;
	int frames;
	int currentFrame;
	int *sequence;
	int *timeInterval;
	bool ended;

	void render();
};

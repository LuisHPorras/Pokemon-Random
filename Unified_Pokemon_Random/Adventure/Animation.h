#pragma once

#include <iostream>
#include <SDL.h>
#include "Vector2D.h"
#include "Constants.h"
#include "Timer.h"
#include "Texture.h"

using namespace std;

class Animation
{
public:

	Animation(void);
	~Animation(void);

	bool loadSprite(std::string path);
	void setClips(int inFrames, int *xvec, int *yvec, int *wvec, int *hvec);
	void setSequence(int dim, int *inSequence, int *inTimeInterval);
	void setSequenceB(int dim, int *inSequence);
	void setPosition(Vector2D inpos);
	void setSpaceInterval(Vector2D inStartPosition, Vector2D inEndPosition);
	bool isEnded();
	void start();
	void start(Vector2D inpos);
	void animate();
	void animateB(int inposx, int inposy, int frame);
	bool animate(Vector2D inpos);
	void hold();
	void hold(Vector2D inpos);

private:

	Texture texture;
	SDL_Rect* clips;
	SDL_Rect* currentClip;
	Timer timer;
	Vector2D startPosition, endPosition, position;
	Vector2D spaceInterval;
	int frames;
	int currentFrame;
	int *sequence;
	int *timeInterval;
	bool ended;

	void render(float posx, float posy);
	void renderB(float posx, float posy);
};

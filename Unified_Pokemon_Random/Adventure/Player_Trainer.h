#pragma once

#include <SDL.h>
#include "Constants.h"
#include "Animation.h"
#include "Vector2D.h"

class Player_Trainer
{
public:
	Player_Trainer(void);
	~Player_Trainer(void);

	void move(int inOrientation);
	void animate();
	void animate(Vector2D pos);
	bool loadFromFile();
	Vector2D getPos() { return position; }

private:
	Vector2D position;
	Vector2D prevPos;
	int orientation;
	Animation animation[Constants::KEY_PRESS_DIRECTION_TOTAL];

	int nclips = 3;
	int xvec[3] = { 0,64,128 };
	int yvec[3] = { 0,0,0 };
	int wvec[3] = { 64,64,64 };
	int hvec[3] = { 64,64,64 };
	int sequence[3] = { 1,0,2 };
	int dim = 3;
	int period = 50;
	int timeInterval[3] = {period,period*2,period*2};
};






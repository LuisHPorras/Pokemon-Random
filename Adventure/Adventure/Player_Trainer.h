#pragma once

#include <SDL.h>
#include "Constants.h"
#include "Texture.h"
#include "Animation.h"
#include "Vector2D.h"

class Player_Trainer
{
public:
	Player_Trainer(void);
	~Player_Trainer(void);

	void move(int inOrientation);
	void animate();

private:
	Vector2D position;
	Vector2D prevPos;
	int orientation;
	Animation animation[Constants::KEY_PRESS_DIRECTION_TOTAL];
};






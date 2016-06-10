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

	void move(int orientation);
	void stand(int orientation);

private:
	Vector2D position;
	Animation animation[Constants::KEY_PRESS_DIRECTION_TOTAL];
};






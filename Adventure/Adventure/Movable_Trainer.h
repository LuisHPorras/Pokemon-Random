#pragma once

#include <SDL.h>
#include "Constants.h"
#include "Texture.h"
#include "Animation.h"
#include "Vector2D.h"

class Movable_Trainer
{
public:
	Movable_Trainer(int posx, int posy);
	~Movable_Trainer();

	void move(int inOrientation);
	void animate();

private:
	Vector2D position;
	Vector2D prevPos;
	int orientation;
	Animation animation[Constants::ORIENTATION_TOTAL];
};






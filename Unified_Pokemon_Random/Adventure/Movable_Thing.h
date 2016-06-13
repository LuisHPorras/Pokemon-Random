#pragma once

#include "Thing.h"
#include "Constants.h"
#include "Animation.h"

enum Orientation
{
	DOWN,
	UP,
	LEFT,
	RIGHT,
	ORIENTATION_TOTAL
};

class Movable_Thing: public Thing
{
public:
	Movable_Thing();
	~Movable_Thing();

	bool loadFromFile();
	bool loadFromSprite(Sprite sprite);
	bool move(Orientation inOrientation);
	void animate();
	void animate(Vector2D pos);

protected:
	Vector2D prevPos;
	Orientation orientation;
	Animation animation[ORIENTATION_TOTAL];

	int nclipsX = 3;
	int nclipsY = 1;

	int xvec[3] = { 0,64,128 };
	int yvec[3] = { 0,0,0 };
	int wvec[3] = { 64,64,64 };
	int hvec[3] = { 64,64,64 };
	int sequence[3] = { 1,0,2 };
	int dim = 3;
	int period = 50;
	int timeInterval[3] = { period,period * 2,period * 2 };

};






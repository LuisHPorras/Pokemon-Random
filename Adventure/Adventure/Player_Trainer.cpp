#include "Player_Trainer.h"

Player_Trainer::Player_Trainer(void)
{
	position.x = 0;
	position.y = 0;
	orientation = 0;
	
	int nclips = 3;
	int xvec[] = { 0,64,128 };
	int yvec[] = { 0,0,0 };
	int wvec[] = { 64,64,64 };
	int hvec[] = { 64,64,64 };
	int sequence[] = { 1,0,2 };
	int dim = 3;
	int period = 25;
	int timeInterval[] = {period/4,period,period};

	animation[Constants::KEY_PRESS_DIRECTION_DOWN].loadSprite("player/player_down_anim2.png");
	animation[Constants::KEY_PRESS_DIRECTION_DOWN].setClips(nclips, xvec, yvec, wvec, hvec);
	animation[Constants::KEY_PRESS_DIRECTION_DOWN].setSequence(dim, sequence, timeInterval);
	animation[Constants::KEY_PRESS_DIRECTION_DOWN].setPosition(position);

	animation[Constants::KEY_PRESS_DIRECTION_UP].loadSprite("player/player_up_anim2.png");
	animation[Constants::KEY_PRESS_DIRECTION_UP].setClips(nclips, xvec, yvec, wvec, hvec);
	animation[Constants::KEY_PRESS_DIRECTION_UP].setSequence(dim, sequence, timeInterval);
	animation[Constants::KEY_PRESS_DIRECTION_UP].setPosition(position);

	animation[Constants::KEY_PRESS_DIRECTION_LEFT].loadSprite("player/player_left_anim2.png");
	animation[Constants::KEY_PRESS_DIRECTION_LEFT].setClips(nclips, xvec, yvec, wvec, hvec);
	animation[Constants::KEY_PRESS_DIRECTION_LEFT].setSequence(dim, sequence, timeInterval);
	animation[Constants::KEY_PRESS_DIRECTION_LEFT].setPosition(position);

	animation[Constants::KEY_PRESS_DIRECTION_RIGHT].loadSprite("player/player_right_anim2.png");
	animation[Constants::KEY_PRESS_DIRECTION_RIGHT].setClips(nclips, xvec, yvec, wvec, hvec);
	animation[Constants::KEY_PRESS_DIRECTION_RIGHT].setSequence(dim, sequence, timeInterval);
	animation[Constants::KEY_PRESS_DIRECTION_RIGHT].setPosition(position);
}


Player_Trainer::~Player_Trainer(void)
{
}

void Player_Trainer::move(int inOrientation)
{
	if (animation[inOrientation].isEnded()&&(animation[orientation].isEnded() || orientation == -1))
	{
		prevPos = position;
		orientation = inOrientation;

		switch (orientation)
		{
			//El eje y está invertido
		case Constants::KEY_PRESS_DIRECTION_DOWN:
			position.y += Constants::PLAYER_HEIGTH;
			break;
		case Constants::KEY_PRESS_DIRECTION_UP:
			position.y -= Constants::PLAYER_HEIGTH;
			break;
		case Constants::KEY_PRESS_DIRECTION_LEFT:
			position.x -= Constants::PLAYER_WIDTH;
			break;
		case Constants::KEY_PRESS_DIRECTION_RIGHT:
			position.x += Constants::PLAYER_WIDTH;
			break;
		default:
			break;
		}

		animation[orientation].setSpaceInterval(prevPos, position);
		animation[orientation].start();
	}
}

void Player_Trainer::animate()
{
	if(animation[orientation].isEnded())
		animation[orientation].hold();
	else
		animation[orientation].animate();
}
#include "Player_Trainer.h"


Player_Trainer::Player_Trainer(void)
{
	int xvec[] = { 0,64,128 };
	int yvec[] = { 0,0,0 };
	int wvec[] = { 64,64,64 };
	int hvec[] = { 64,64,64};
	int sequence[] = { 1,0,1,2 };
	int period = 50;
	int timeInterval[] = {period*2,period,period*2,period};



	animation[Constants::KEY_PRESS_DIRECTION_DOWN].loadSprite("player/player_down_anim2.png");
	animation[Constants::KEY_PRESS_DIRECTION_DOWN].setClips(3, xvec, yvec, wvec, hvec);
	animation[Constants::KEY_PRESS_DIRECTION_DOWN].setSequence();
	animation[Constants::KEY_PRESS_DIRECTION_DOWN].setSpaceInterval();

	animation[Constants::KEY_PRESS_DIRECTION_UP].loadSprite("player/player_up_anim2.png");
	animation[Constants::KEY_PRESS_DIRECTION_DOWN].setClips(3, xvec, yvec, wvec, hvec);

	animation[Constants::KEY_PRESS_DIRECTION_LEFT].loadSprite("player/player_left_anim2.png");
	animation[Constants::KEY_PRESS_DIRECTION_DOWN].setClips(3, xvec, yvec, wvec, hvec);

	animation[Constants::KEY_PRESS_DIRECTION_RIGHT].loadSprite("player/player_right_anim2.png");
	animation[Constants::KEY_PRESS_DIRECTION_DOWN].setClips(3, xvec, yvec, wvec, hvec);

	position.x = 0;
	position.y = 0;
}


Player_Trainer::~Player_Trainer(void)
{
}


void Player_Trainer::move(int orientation)
{
	switch (orientation)
	{
		//El eje y está invertido
	case Constants::KEY_PRESS_DIRECTION_DOWN:
		position.y += PLAYER_HEIGTH;
		break;
	case Constants::KEY_PRESS_DIRECTION_UP:
		position.y -= PLAYER_HEIGTH;
		break;
	case Constants::KEY_PRESS_DIRECTION_LEFT:
		position.x -= PLAYER_WIDTH;
		break;
	case Constants::KEY_PRESS_DIRECTION_RIGHT:
		position.x += PLAYER_WIDTH;
		break;
	default:
		break;
	}
	animation[orientation].render(position, true);
}


void Player_Trainer::stand(int orientation)
{
	animation[orientation].render(position);
}
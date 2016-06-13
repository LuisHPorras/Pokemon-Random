#include "Player_Trainer.h"

Player_Trainer::Player_Trainer(void)
{
	position.x = 0;
	position.y = 0;
	orientation = 0;
}

Player_Trainer::~Player_Trainer(void)
{
}

bool Player_Trainer::loadFromFile()
{
	if (!animation[Constants::KEY_PRESS_DIRECTION_DOWN].loadFromFile("player/player_down_anim2.png"))
		return false;
	animation[Constants::KEY_PRESS_DIRECTION_DOWN].setClips(nclipsX, nclipsY, xvec, yvec, wvec, hvec);
	animation[Constants::KEY_PRESS_DIRECTION_DOWN].setSequence(dim, sequence, timeInterval);
	animation[Constants::KEY_PRESS_DIRECTION_DOWN].setPosition(position);

	if (!animation[Constants::KEY_PRESS_DIRECTION_UP].loadFromFile("player/player_up_anim2.png"))
		return false;
	animation[Constants::KEY_PRESS_DIRECTION_UP].setClips(nclipsX, nclipsY, xvec, yvec, wvec, hvec);
	animation[Constants::KEY_PRESS_DIRECTION_UP].setSequence(dim, sequence, timeInterval);
	animation[Constants::KEY_PRESS_DIRECTION_UP].setPosition(position);

	if (!animation[Constants::KEY_PRESS_DIRECTION_LEFT].loadFromFile("player/player_left_anim2.png"))
		return false;
	animation[Constants::KEY_PRESS_DIRECTION_LEFT].setClips(nclipsX, nclipsY, xvec, yvec, wvec, hvec);
	animation[Constants::KEY_PRESS_DIRECTION_LEFT].setSequence(dim, sequence, timeInterval);
	animation[Constants::KEY_PRESS_DIRECTION_LEFT].setPosition(position);

	if (!animation[Constants::KEY_PRESS_DIRECTION_RIGHT].loadFromFile("player/player_right_anim2.png"))
		return false;
	animation[Constants::KEY_PRESS_DIRECTION_RIGHT].setClips(nclipsX, nclipsY, xvec, yvec, wvec, hvec);
	animation[Constants::KEY_PRESS_DIRECTION_RIGHT].setSequence(dim, sequence, timeInterval);
	animation[Constants::KEY_PRESS_DIRECTION_RIGHT].setPosition(position);
}

void Player_Trainer::move(int inOrientation)
{
	if (animation[inOrientation].isEnded()&&animation[orientation].isEnded())
	{
		orientation = inOrientation;
		prevPos = position;

		switch (orientation)
		{
			//El eje y está invertido
		case Constants::KEY_PRESS_DIRECTION_DOWN:
			position.y++;
			break;
		case Constants::KEY_PRESS_DIRECTION_UP:
			position.y--;
			break;
		case Constants::KEY_PRESS_DIRECTION_LEFT:
			position.x--;
			break;
		case Constants::KEY_PRESS_DIRECTION_RIGHT:
			position.x++;
			break;
		default:
			break;
		}
		animation[orientation].start();
	}
}

void Player_Trainer::setRelPos(Vector2D pos)
{
	//MALLLLLLLLLLLLL
	if (position == position - pos)
	{
		position -= pos;
		if(pos.x == 0 && pos.y == 0)
			animation[orientation].setSpaceInterval(prevPos*Constants::TILE_DIM, position*Constants::TILE_DIM);
		else
			animation[orientation].setSpaceInterval(position*Constants::TILE_DIM, position*Constants::TILE_DIM);
	}	
}

void Player_Trainer::animate()
{
	if(animation[orientation].isEnded())
		animation[orientation].hold();
	else
		animation[orientation].animate();
}

void Player_Trainer::animate(Vector2D pos)
{
	if (animation[orientation].isEnded())
		animation[orientation].hold(pos*Constants::TILE_DIM);
	else
		animation[orientation].animate(pos*Constants::TILE_DIM);
}

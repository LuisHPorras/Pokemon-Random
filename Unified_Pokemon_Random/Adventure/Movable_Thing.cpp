#include "Movable_Thing.h"

Movable_Thing::Movable_Thing()
{
}

Movable_Thing::~Movable_Thing()
{
}

bool Movable_Thing::loadFromFile()
{
	if (!animation[Constants::KEY_PRESS_DIRECTION_DOWN].loadFromFile("player/player_down_anim2.png"))
		return false;
	animation[Constants::KEY_PRESS_DIRECTION_DOWN].setClips(nclipsX, nclipsY, xvec, yvec, wvec, hvec);
	animation[Constants::KEY_PRESS_DIRECTION_DOWN].setSequence(dim, sequence, timeInterval);
	animation[Constants::KEY_PRESS_DIRECTION_DOWN].setPosition(position*Constants::TILE_DIM);

	if (!animation[Constants::KEY_PRESS_DIRECTION_UP].loadFromFile("player/player_up_anim2.png"))
		return false;
	animation[Constants::KEY_PRESS_DIRECTION_UP].setClips(nclipsX, nclipsY, xvec, yvec, wvec, hvec);
	animation[Constants::KEY_PRESS_DIRECTION_UP].setSequence(dim, sequence, timeInterval);
	animation[Constants::KEY_PRESS_DIRECTION_UP].setPosition(position*Constants::TILE_DIM);

	if (!animation[Constants::KEY_PRESS_DIRECTION_LEFT].loadFromFile("player/player_left_anim2.png"))
		return false;
	animation[Constants::KEY_PRESS_DIRECTION_LEFT].setClips(nclipsX, nclipsY, xvec, yvec, wvec, hvec);
	animation[Constants::KEY_PRESS_DIRECTION_LEFT].setSequence(dim, sequence, timeInterval);
	animation[Constants::KEY_PRESS_DIRECTION_LEFT].setPosition(position*Constants::TILE_DIM);

	if (!animation[Constants::KEY_PRESS_DIRECTION_RIGHT].loadFromFile("player/player_right_anim2.png"))
		return false;
	animation[Constants::KEY_PRESS_DIRECTION_RIGHT].setClips(nclipsX, nclipsY, xvec, yvec, wvec, hvec);
	animation[Constants::KEY_PRESS_DIRECTION_RIGHT].setSequence(dim, sequence, timeInterval);
	animation[Constants::KEY_PRESS_DIRECTION_RIGHT].setPosition(position*Constants::TILE_DIM);

	return true;
}

bool Movable_Thing::loadFromSprite(Sprite sprite)
{
	return true;
}

bool Movable_Thing::move(Orientation inOrientation)
{
	if (animation[inOrientation].isEnded() && animation[orientation].isEnded())
	{
		orientation = inOrientation;
		prevPos = position;

		switch (orientation)
		{
		case DOWN:
			position.y++;
			break;
		case UP:
			position.y--;
			break;
		case LEFT:
			position.x--;
			break;
		case RIGHT:
			position.x++;
			break;
		default:
			break;
		}
		animation[orientation].start();
		animation[orientation].setSpaceInterval(prevPos*Constants::TILE_DIM, position*Constants::TILE_DIM);
		return true;
	}
	return false;
}

void Movable_Thing::animate()
{
	if (animation[orientation].isEnded())
		animation[orientation].hold();
	else
		animation[orientation].animate();
}

void Movable_Thing::animate(Vector2D pos)
{
	if (animation[orientation].isEnded())
		animation[orientation].hold(pos*Constants::TILE_DIM);
	else
		animation[orientation].animate(pos*Constants::TILE_DIM);
}

void Movable_Thing::setRelPos(Vector2D pos)
{
	animation[orientation].setSpaceInterval((prevPos - pos)*Constants::TILE_DIM, (position - pos)*Constants::TILE_DIM);
}

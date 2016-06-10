#include "Movable_Trainer.h"

Movable_Trainer::Movable_Trainer(int posx, int posy)
{
	position.x = posx;
	position.y = posy;
	orientation = 0;

	int nclips = 3;
	int xvec[] = { 0 * Constants::PLAYER_WIDTH,1 * Constants::PLAYER_WIDTH,2 * Constants::PLAYER_WIDTH };
	int yvec[] = { 0,0,0 };
	int wvec[] = { Constants::PLAYER_WIDTH,Constants::PLAYER_WIDTH,Constants::PLAYER_WIDTH };
	int hvec[] = { Constants::PLAYER_HEIGTH,Constants::PLAYER_HEIGTH,Constants::PLAYER_HEIGTH };
	int sequence[] = { 1,0,2 };
	int dim = 3;
	int period = 50;
	int timeInterval[] = { period,period * 2,period * 2 };

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


//	int nclips = 3;
//	int xvec[] = { 0,64,128 };
//	int yvec[] = { 700,700,700 };
//	int wvec[] = { 64,64,64 };
//	int hvec[] = { 64,64,64 };//64,64,64
//	int sequence[] = { 1,0,2 };
//	int dim = 3;
//	int period = 50;
//	int timeInterval[] = { period,period * 2,period * 2 };
//
//	/*int nclips = 4;
//	int xvec[] = { 783,815,857,889 };
//	int yvec[] = { 72,72,72,72 };
//	int wvec[] = { 64,64,64,64 };
//	int hvec[] = { 32,32,32,32 };
//	int sequence[] = { 0,1,2,3 };
//	int dim = 4;
//	int period = 50;
//	int timeInterval[] = { period,period * 2,period,period * 2 };*/
//
//	animation[Constants::ORIENTATION_DOWN].loadSprite("johtopokemon2.png");
//	animation[Constants::ORIENTATION_DOWN].setClips(nclips, xvec, yvec, wvec, hvec);
//	animation[Constants::ORIENTATION_DOWN].setSequence(dim, sequence, timeInterval);
//	animation[Constants::ORIENTATION_DOWN].setPosition(position);
//
//	animation[Constants::ORIENTATION_UP].loadSprite("johtopokemon2.png");
//	animation[Constants::ORIENTATION_UP].setClips(nclips, xvec, yvec, wvec, hvec);
//	animation[Constants::ORIENTATION_UP].setSequence(dim, sequence, timeInterval);
//	animation[Constants::ORIENTATION_UP].setPosition(position);
//
//	animation[Constants::ORIENTATION_LEFT].loadSprite("johtopokemon2.png");
//	animation[Constants::ORIENTATION_LEFT].setClips(nclips, xvec, yvec, wvec, hvec);
//	animation[Constants::ORIENTATION_LEFT].setSequence(dim, sequence, timeInterval);
//	animation[Constants::ORIENTATION_LEFT].setPosition(position);
//
//	animation[Constants::ORIENTATION_RIGHT].loadSprite("johtopokemon2.png");
//	animation[Constants::ORIENTATION_RIGHT].setClips(nclips, xvec, yvec, wvec, hvec);
//	animation[Constants::ORIENTATION_RIGHT].setSequence(dim, sequence, timeInterval);
//	animation[Constants::ORIENTATION_RIGHT].setPosition(position);
}

Movable_Trainer::~Movable_Trainer()
{
}

void Movable_Trainer::move(int inOrientation)
{
	if (animation[inOrientation].isEnded() && (animation[orientation].isEnded() || orientation == -1))
	{
		prevPos = position;
		orientation = inOrientation;

		switch (orientation)
		{
			//El eje y está invertido
		case Constants::ORIENTATION_DOWN:
			position.y += Constants::PLAYER_HEIGTH / 4;
			break;
		case Constants::ORIENTATION_UP:
			position.y -= Constants::PLAYER_HEIGTH / 4;
			break;
		case Constants::ORIENTATION_LEFT:
			position.x -= Constants::PLAYER_WIDTH / 4;
			break;
		case Constants::ORIENTATION_RIGHT:
			position.x += Constants::PLAYER_WIDTH / 4;
			break;
		default:
			break;
		}

		animation[orientation].setSpaceInterval(prevPos, position);
		animation[orientation].start();
	}
}

void Movable_Trainer::animate()
{
	if (animation[orientation].isEnded())
		animation[orientation].hold();
	else
		animation[orientation].animate();
}

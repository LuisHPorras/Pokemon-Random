#include "Player_Trainer.h"

Player_Trainer::Player_Trainer(void)
{
}

Player_Trainer::~Player_Trainer(void)
{
}

void Player_Trainer::setRelPos(Vector2D pos)
{
	animation[orientation].setSpaceInterval((position-pos)*Constants::TILE_DIM, (position - pos)*Constants::TILE_DIM);//Dont move if the camera is moving	
}


#include "Enemy.h"

//CONSTRUCTION - DESTRUCTION
Enemy::Enemy(int xh):
	//HP, Name, Level
	Pokemon(150, 72, 10, 31, 246+10, 31)
{
	Health.x = 0;
	groundMultiplier = 1.75f;
}

Enemy::~Enemy()
{
}

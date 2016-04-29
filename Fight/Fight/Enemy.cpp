#include "Enemy.h"

//CONSTRUCTION - DESTRUCTION
Enemy::Enemy(int xh):
	//HP, Name, Level
	Pokemon(150, 72, 10, 31, 246+10, 31)
{
	maxHP = 80;
	currentHP = 80;
	attack = 120;
	defence = 130;
	Health.x = 0;
	groundMultiplier = 1.75f;
	type = rock;
}

Enemy::~Enemy()
{
}

#include "Enemy.h"


Enemy::Enemy():
	Pokemon(150, 72, 10, 31, 246 + 10, 31)
{
	groundMultiplyer = 1.75f;
	posData.x = 0;
}


Enemy::~Enemy(void)
{
}

bool Enemy::loadFromFile()
{
	bool success = Pokemon::loadFromFile();

	if (!ground.loadFromFile("Texturas/battle_base_wild_enemy.png"))
	{
		cout << "Failed to load ground texture image!" << endl;
		success = false;
	}

	if (!data.loadFromFile("Texturas/healthbar_enemy.png"))
	{
		cout << "Failed to load data texture image!" << endl;
		success = false;
	}

	return success;
}
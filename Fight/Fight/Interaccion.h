#include "Player.h"
#include "Enemy.h"

#pragma once
class Interaccion
{
public:
	//CONSTRUCTION - DESTRUCTION
	Interaccion();
	~Interaccion();

	//SATIC METHODS
	static void attack(Player &player, Enemy &enemy, Attack &strike);
};


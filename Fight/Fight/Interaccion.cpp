#include "Interaccion.h"

//CONSTRUCTION - DESTRUCTION
Interaccion::Interaccion()
{
}

Interaccion::~Interaccion()
{
}

//STATIC METHODS
void Interaccion::attack(Player &player, Enemy &enemy, Attack &strike)
{
	float stab = 1.0f;
	float effectiveness = 1.0f;
	enemy.currentHP = enemy.currentHP - (int)(stab * effectiveness * ((0.2 * player.Lv + 1) * player.attack * strike.power / 25 / enemy.defence + 2));
	if (enemy.currentHP < 0) enemy.currentHP = 0;
}

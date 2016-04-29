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
	//STAB is 1.5 if the attack is of the same type as the user
	float stab = 1.0f;
	if (player.type == strike.type)
		stab = 1.5f;

	float effectiveness = 1.0f;
	if ((enemy.type == flying && strike.type == fighting) || (enemy.type == fighting && strike.type == rock) || (enemy.type == rock && strike.type == flying))
		effectiveness = 0.5f;
	if ((enemy.type == flying && strike.type == rock) || (enemy.type == rock && strike.type == fighting) || (enemy.type == fighting && strike.type == flying))
		effectiveness = 2.0f;

	enemy.currentHP = enemy.currentHP - (int)(stab * effectiveness * ((0.2 * player.Lv + 1) * player.attack * strike.power / 25 / enemy.defence + 2));
	if (enemy.currentHP < 0) enemy.currentHP = 0;
}

#pragma once

#include "Layer.h"
#include "Player_Trainer.h"
#include <stdlib.h>

class Interaction
{
public:
	Interaction();
	~Interaction();

	static void interaction(Layer* l, Movable_Thing* t);
	static Constants::State interaction(Layer* l, Player_Trainer* t);

};


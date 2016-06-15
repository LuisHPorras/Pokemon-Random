#pragma once

#include "Layer.h"
#include "Player_Trainer.h"

class Interaction
{
public:
	Interaction();
	~Interaction();

	static void interaction(Layer* l, Movable_Thing* t);

};


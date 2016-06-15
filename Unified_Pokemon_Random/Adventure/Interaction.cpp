#include "Interaction.h"

Interaction::Interaction()
{
}

Interaction::~Interaction()
{
}

void Interaction::interaction(Layer* l, Movable_Thing* t)
{
	if(l->getTile(t->getPos()))
		switch (l->getType())
		{
		case Constants::NOTWALKABLE:
			t->setPos(t->getPrevPos());
			break;
		case Constants::TALLGRASS:
			t->setRenderTallGrass();
			break;
		case Constants::WATER:
			dynamic_cast<Player_Trainer*>(t)->swimmingRequest();
			break;
		default:
			break;
		}

}
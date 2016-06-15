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
		case Constants::WATER:
		case Constants::NOTWALKABLE:
			t->setPos(t->getPrevPos());
			break;
		case Constants::TALLGRASS:
			t->setRenderTallGrass();
			break;
		case Constants::ENTRANCE:
			t->setRenderTallGrass();
			break;
		//case Constants::WATER:
		//	dynamic_cast<Player_Trainer*>(t)->swimmingRequest();
		//	break;
		default:
			break;
		}
}

Constants::State Interaction::interaction(Layer* l, Player_Trainer* t)
{
	int randNum;
	if (l->getTile(t->getPos()))
		switch (l->getType())
		{
		case Constants::WATER:
		case Constants::NOTWALKABLE:
			t->setPos(t->getPrevPos());
			break;
		case Constants::TALLGRASS:
			t->setRenderTallGrass();
			randNum = rand() % 100 + 1;
			if (t->getBattleFlag())
				if (randNum > 50)
				{
					return Constants::FIGHT;
					t->setBattleFlag(false);
				}
			break;
		case Constants::ENTRANCE:
			t->setRenderTallGrass();
			break;
			//case Constants::WATER:
			//	dynamic_cast<Player_Trainer*>(t)->swimmingRequest();
			//	break;
		default:
			break;
		}

	return Constants::ADVENTURE;

}
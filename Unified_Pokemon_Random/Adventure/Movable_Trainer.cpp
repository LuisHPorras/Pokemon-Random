#include "Movable_Trainer.h"

Movable_Trainer::Movable_Trainer(): trajIndex(0), trajDim(0)
{
}

Movable_Trainer::~Movable_Trainer()
{
}

void Movable_Trainer::setSprite()
{

}

void Movable_Trainer::setTrajectory(int dim, Orientation *t)
{
	trajDim = dim;
	trajectory = t;
}

void Movable_Trainer::walk()
{
	if (trajIndex == trajDim)
		trajIndex = 0;
	if (move(trajectory[trajIndex]))
		trajIndex++;
}


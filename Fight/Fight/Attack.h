#include "Texture.h"

#pragma once
class Attack
{
	string name;

	//STATS
	int power;
public:
	//CONSTRUCTION - DESTRUCTION
	Attack(string sname, int pow=0);
	~Attack();

	//INTERFACE INLINE METHODS
	int getPower(){return power;}
};


#include "Texture.h"

enum types
	{
		flying,
		fighting,
		rock
	};

#pragma once
class Attack
{
	string name;
	
	//STATS
	int power;
	types type;
public:
	//CONSTRUCTION - DESTRUCTION
	Attack(string sname, types ctype, int pow=0);
	~Attack();

	//INTERFACE INLINE METHODS
	int getPower(){return power;}

	//FRIENDS
	friend class Interaccion;
};


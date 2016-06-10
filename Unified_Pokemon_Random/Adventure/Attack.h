#pragma once

#include <iostream>
#include "Constants.h"

using namespace std;

class Attack
{
	string name;

	//STATS
	int power;
	Constants::Types type;
public:
	//CONSTRUCTION - DESTRUCTION
	Attack(void);
	~Attack(void);

	//INTERFACE INLINE METHODS
	int getPower(){return power;}
};


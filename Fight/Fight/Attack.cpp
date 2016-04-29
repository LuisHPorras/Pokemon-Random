#include "Attack.h"

//CONSTRUCTION - DESTRUCTION
Attack::Attack(string sname, types ctype, int pow)
{
	name = sname;
	type = ctype;
	power = pow;
}

Attack::~Attack()
{
}

#include "Vector2D.h"

//CONSTRUCTION - DESTRUCTION
Vector2D::Vector2D(int ix , int iy)
{
	x = ix;
	y = iy;
}


Vector2D::~Vector2D()
{
}

//OPERATORS
bool Vector2D::operator==(Vector2D v)
{
	if (x == v.x && y == v.y)
		return true;
	else
		return false;
}
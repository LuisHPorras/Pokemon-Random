#include "Vector2D.h"


Vector2D::Vector2D(int ix, int iy)
{
	x = ix;
	y = iy;
}


Vector2D::~Vector2D(void)
{
}

bool Vector2D::operator==(Vector2D v)
{
	if (x == v.x && y == v.y)
		return true;
	return false;
}

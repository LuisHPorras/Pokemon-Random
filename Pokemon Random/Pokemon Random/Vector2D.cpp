#include "Vector2D.h"

Vector2D::Vector2D(void)
{
}

Vector2D::~Vector2D(void)
{
}

Vector2D Vector2D::operator - (Vector2D v2)
{
	Vector2D result;

	result.x = x - v2.x;
	result.y = y - v2.y;

	return result;
}

Vector2D Vector2D::operator / (int n)
{
	Vector2D result;

	(int)result.x = x / n;
	(int)result.y = y / n;

	return result;
}

Vector2D Vector2D::operator * (int n)
{
	Vector2D result;

	(int)result.x = x * n;
	(int)result.y = y * n;

	return result;
}
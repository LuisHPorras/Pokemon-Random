#pragma once
class Vector2D
{
public:
	//COORDINATES
	int x;
	int y;

	//CONSTRUCTION - DESTRUCTION
	Vector2D(int ix=0, int iy=0);
	~Vector2D();

	//OPERATORS
	bool operator==(Vector2D v);
};


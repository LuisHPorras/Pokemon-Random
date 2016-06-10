#pragma once
class Vector2D
{	
public:
	int x;
	int y;

	Vector2D(int ix = 0, int iy = 0);
	~Vector2D(void);

	bool operator==(Vector2D v);
};


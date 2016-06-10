#pragma once
class Vector2D
{
public:
	Vector2D(void);
	~Vector2D(void);
	
	Vector2D operator - (Vector2D v2);
	Vector2D operator / (int n);
	Vector2D operator * (int n);

	int x;
	int y;

};


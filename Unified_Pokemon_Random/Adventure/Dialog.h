#pragma once

#include "Texture.h"
#include "Vector2D.h"
#include "ListOf.h"
#include "Fight.h"

class Dialog
{
	Texture menu;
	Texture info;
	Texture cursor;
	Vector2D pcursor;

	ListOf<string> soption;
	ListOf<Texture> toption;
	ListOf<Vector2D> option;
public:
	Dialog(ListOf<Vector2D> inoptions);
	~Dialog();

	bool loadFromFile();
	void render(int x, int y);
	void free();
//	void events(Fight::States state);

	int getWidth() { return menu.getWidth(); }
	int getHeight() { return menu.getHeight(); }
};


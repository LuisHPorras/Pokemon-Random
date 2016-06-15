#pragma once

#include "Texture.h"
#include "Vector2D.h"
#include "ListOf.h"
#include "Constants.h"

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
	Dialog();
	~Dialog();

	bool loadFromFile();
	void render(int x, int y);
	void free();
	void events(Constants::FightState state, Vector2D posCursor);
	void updateOptions(ListOf<Vector2D> inoptions);

	int getWidth() { return menu.getWidth(); }
	int getHeight() { return menu.getHeight(); }
};

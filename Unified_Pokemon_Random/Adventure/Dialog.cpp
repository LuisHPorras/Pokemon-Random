#include "Dialog.h"



Dialog::Dialog(ListOf<Vector2D> inoptions) :
	option(inoptions)
{
	for (int i = 0; i < 4; i++)
	{
		soption += new string;
		toption += new Texture;
	}
}

Dialog::~Dialog()
{
	free();
	toption.erase();
	soption.erase();
}

bool Dialog::loadFromFile()
{
	bool success = true;

	if (!menu.loadFromFile("Texturas/menu3.png"))
	{
		cout << "Failed to load menu texture image!" << endl;
		success = false;
	}

	if (!info.loadFromFile("Texturas/menu4.png"))
	{
		cout << "Failed to load info texture image!" << endl;
		success = false;
	}

	if (!cursor.loadFromFile("Texturas/ball_small.png"))
	{
		cout << "Failed to load cursor texture image!" << endl;
		success = false;
	}

	return success;
}

void Dialog::render(int x, int y)
{
	menu.render(x, y);
	info.render(x + menu.getWidth() - info.getWidth(), y);
	cursor.render(x + pcursor.x, y + pcursor.y);
	for (int i = 0; i < option.getNumber(); i++)
		toption[i].render(x + option[i].x + 10 + cursor.getWidth(), y + option[i].y);
}

void Dialog::free()
{
	menu.free();
	info.free();
	cursor.free();
	for (int i = 0; i < toption.getNumber(); i++)
		toption[i].free();
}

void Dialog::events(Constants::FightState state)
{
	for (int i = 0; i < toption.getNumber(); i++)
		toption[i].free();

	if (state == Constants::MAIN)
	{
		soption[0] = "Attack";
		soption[1] = "Pokemon";
		soption[2] = "Objects";
		soption[3] = "Escape";
	}

	for (int i = 0; i < toption.getNumber(); i++)
		toption[i].loadFromRenderedText(soption[i]);
}
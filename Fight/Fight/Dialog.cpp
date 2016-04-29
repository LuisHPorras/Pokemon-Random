#include "Dialog.h"

extern SDL_Color textColor;

//CONSTRUCTION - DESTRUCTION
Dialog::Dialog():
	poption1(100, 40),
	poption2(475, 40),
	poption3(100, 130),
	poption4(475, 130)
{
	pcursor = poption4;
	state = options;
}

Dialog::~Dialog()
{
}

//MEDIA METHODS
bool Dialog::loadFromFile(string menu3, string pcursor)
{
	bool success = true;

	if (!dialog.loadFromFile(menu3))
	{
		cout<<"Failed to load dialog texture image!"<<endl;
		success = false;
	}

	if (!cursor.loadFromFile(pcursor))
	{
		cout<<"Failed to load cursor texture image!"<<endl;
		success = false;
	}

	return success;
}

void Dialog::render(int x, int y)
{
	if (!textUpdate(state))
		cout<<"Failed to update text texture images!"<<endl;

	dialog.render(x, y);
	option1.render(x + poption1.x + 10 + cursor.getWidth(), y + poption1.y);
	option2.render(x + poption2.x + 10 + cursor.getWidth(), y + poption2.y);
	option3.render(x + poption3.x + 10 + cursor.getWidth(), y + poption3.y);
	option4.render(x + poption4.x + 10 + cursor.getWidth(), y + poption4.y);
	cursor.render(x + pcursor.x, y + pcursor.y);
}

void Dialog::free()
{
	dialog.free();
	option1.free();
	option2.free();
	option3.free();
	option4.free();
	cursor.free();
}

bool Dialog::textUpdate(states cstate)
{
	bool success = true;

	//Delete all previous textures
	option1.free();
	option2.free();
	option3.free();
	option4.free();

	//Defines text labels
	if (cstate == options)
	{
		soption1 = "Attack";
		soption2 = "Pokemon";
		soption3 = "Object";
		soption4 = "Escape";
	}
	if (cstate == attack)
	{
		soption1 = "Drill Peck";
		soption2 = "---";
		soption3 = "---";
		soption4 = "---";
	}
	if (cstate == pokemon)
	{
		soption1 = "Sorry dude, not yet implemented";
		soption2 = " ";
		soption3 = " ";
		soption4 = " ";
	}
	if (cstate == object)
	{
		soption1 = "Sorry dude, not yet implemented";
		soption2 = " ";
		soption3 = " ";
		soption4 = " ";
	}
	if (cstate == escape)
	{
		soption1 = "Sorry dude, not yet implemented";
		soption2 = " ";
		soption3 = " ";
		soption4 = " ";
	}

	//Loads text sufaces
	if (!option1.loadFromRenderedText(soption1, textColor))
	{
		cout<<"Failed to load option1 texture image!"<<endl;
		success = false;
	}

	if (!option2.loadFromRenderedText(soption2, textColor))
	{
		cout<<"Failed to load option2 texture image!"<<endl;
		success = false;
	}

	if (!option3.loadFromRenderedText(soption3, textColor))
	{
		cout<<"Failed to load option3 texture image!"<<endl;
		success = false;
	}

	if (!option4.loadFromRenderedText(soption4, textColor))
	{
		cout<<"Failed to load option4 texture image!"<<endl;
		success = false;
	}

	return success;
}

void Dialog::events(SDL_Event &e)
{
	if (e.type == SDL_KEYDOWN)
	{
		switch(e.key.keysym.sym)
		{
		case SDLK_UP:
			if (pcursor == poption1 || pcursor == poption2)
				break;
			if (pcursor == poption3)
				pcursor = poption1;
			if (pcursor == poption4)
				pcursor = poption2;
			break;
		case SDLK_DOWN:
			if (pcursor == poption3 || pcursor == poption4)
				break;
			if (pcursor == poption1)
				pcursor = poption3;
			if (pcursor == poption2)
				pcursor = poption4;
			break;
		case SDLK_LEFT:
			if (pcursor == poption1 || pcursor == poption3)
				break;
			if (pcursor == poption2)
				pcursor = poption1;
			if (pcursor == poption4)
				pcursor = poption3;
			break;
		case SDLK_RIGHT:
			if (pcursor == poption2 || pcursor == poption4)
				break;
			if (pcursor == poption1)
				pcursor = poption2;
			if (pcursor == poption3)
				pcursor = poption4;
			break;
		case SDLK_a:
			if (state == options)
			{
				if (pcursor == poption1)
				{
					state = attack;
					pcursor = poption1;
					break;
				}
				if (pcursor == poption2)
				{
					state = pokemon;
					pcursor = poption1;
					break;
				}
				if (pcursor == poption3)
				{
					state = object;
					pcursor = poption1;
					break;
				}
				if (pcursor == poption4)
				{
					state = escape;
					pcursor = poption1;
					break;
				}
			}
			break;
		case SDLK_s:
			if (state == options)
				break;
			else
			{
				state = options;
				pcursor = poption1;
				break;
			}
		}
	}
}

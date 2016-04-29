#include "Texture.h"
#include "Vector2D.h"

#pragma once
class Dialog
{
	//Texture
	Texture dialog;
	Texture option1;
	Texture option2;
	Texture option3;
	Texture option4;
	Texture cursor;

	//OPTION STRINGS
	string soption1;
	string soption2;
	string soption3;
	string soption4;

	//GRAPHIC POSITIONING PARAMETERS
	Vector2D poption1;
	Vector2D poption2;
	Vector2D poption3;
	Vector2D poption4;
	Vector2D pcursor;

	//STATE
	enum states
	{
		options,
		attack,
		pokemon,
		object,
		escape,
		error,
		attacking
	}state;
public:
	//CONSTRUCTION - DESTRUCTION
	Dialog();
	~Dialog();

	//MEDIA METHODS
	bool loadFromFile(string pmenu3, string pcursor);
	void render(int x, int y);
	void free();
	void events(SDL_Event &e);
	bool textUpdate(states cstate);

	//INTERFACE INLINE METHODS
	int getWidth(){return dialog.getWidth();}
	int getHeight(){return dialog.getHeight();}
};


#include "Player.h"

//CONSTRUCTION - DESTRUCTION
Player::Player(int index):
	//HP, Name and Level positions
	Pokemon(index, 216, 75, 60, 33, 312+10, 33),
	pcurrentHP(210, 92),
	pmaxHP(286+10, 92)
{
	smaxHP = to_string(maxHP);
	scurrentHP = to_string(currentHP);
	groundMultiplyer = 1;
}


Player::~Player(void)
{
}

//GRAPHIC METHODS
bool Player::loadFromFile(string pground, string pdata)
{
	bool success = Pokemon::loadFromFile(pground, pdata);
	updateXData();

	if (!tmaxHP.loadFromRenderedText(smaxHP))
	{
		cout<<"Failed to load maxHP texture from text!"<<endl;
		success = false;
	}

	if (!tcurrentHP.loadFromRenderedText(scurrentHP))
	{
		cout<<"Failed to load currentHP texture from text!"<<endl;
		success = false;
	}

	return success;
}

void Player::render(int x, int y)
{
	Pokemon::render(x, y);
	tcurrentHP.render(posData.x + pcurrentHP.x, posData.y + pcurrentHP.y);
	tmaxHP.render(posData.x + pcurrentHP.x, posData.y + pcurrentHP.y);
}

void Player::free()
{
	Pokemon::free();
	tcurrentHP.free();
	tmaxHP.free();
}

void Player::updateXData()
{
	posData.x = Constants::SCREEN_WIDTH - data.getWidth();
}
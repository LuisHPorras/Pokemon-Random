#include "Fight.h"

extern SDL_Color textColor;

//CONSTRUCTION - DESTRUCTION
Player::Player():
	//HP, Name, Level Position
	Pokemon(216, 75, 60, 33, 312+10, 33),
	pcurrentHp(210, 92),
	pmaxHp(286 + 10, 92),
	DrillPeck("Drill Peck", 80)
{
	maxHP = 60;
	currentHP = maxHP;
	attack = 110;
	defence = 70;
	smaxHp = to_string(maxHP);
	scurrentHp = to_string(currentHP);
	groundMultiplier = 1;
}


Player::~Player()
{
}

//MEDIA METHODS
bool Player::loadFromFile(string pbody, string pground, string pdata, string tname)
{
	bool success = Pokemon::loadFromFile(pbody, pground, pdata, tname);
	updateXHealth();

	if (!tmaxHp.loadFromRenderedText(smaxHp, textColor))
	{
		cout<<"Failed to load maxHp texture image"<<endl;
		success = false;
	}

	if (!tcurrentHp.loadFromRenderedText(scurrentHp, textColor))
	{
		cout<<"Failed to load currentHp texture image"<<endl;
		success = false;
	}

	return success;
}

void Player::render(int x, int y)
{
	Pokemon::render(x, y);
	tcurrentHp.render(Health.x + pcurrentHp.x, Health.y + pcurrentHp.y);
	tmaxHp.render(Health.x + pmaxHp.x, Health.y + pmaxHp.y);
}

void Player::free()
{
	Pokemon::free();
	tcurrentHp.free();
	tmaxHp.free();
}

void Player::updateXHealth()
{
	Health.x = Fight::SCREEN_WIDTH - data.getWidth();
}

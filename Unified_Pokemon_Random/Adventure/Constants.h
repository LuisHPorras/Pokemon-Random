#pragma once
class Constants
{
public:
	Constants();
	~Constants();

	//The dimensions of the level
	static const int LEVEL_WIDTH = 1280;
	static const int LEVEL_HEIGHT = 960;

	//Screen dimension constants
	static const int SCREEN_WIDTH = 800;
	static const int SCREEN_HEIGHT = 600;

	static const int DIM = 400;

	static const int PLAYER_WIDTH = 64;
	static const int PLAYER_HEIGHT = 64;

	static const int NUM_PKMN_DEX = 2;
	static const int NUM_STATS_DEX = 6;

	enum State
	{
		ADVENTURE,
		FIGHT,
		STATE_TOTAL
	};

	enum Orientations
	{
		ORIENTATION_DOWN,
		ORIENTATION_UP,
		ORIENTATION_LEFT,
		ORIENTATION_RIGHT,
		ORIENTATION_TOTAL,
	};

	enum KeyPressDirection
	{
		KEY_PRESS_DIRECTION_DOWN,
		KEY_PRESS_DIRECTION_UP,
		KEY_PRESS_DIRECTION_LEFT,
		KEY_PRESS_DIRECTION_RIGHT,
		KEY_PRESS_DIRECTION_TOTAL,
		KEY_PRESS_DIRECTION_DEFAULT
	};

	enum Types {
		FLYING,
		FIGHTING,
		ROCK,
		TOTAL_TYPES
	};
};


#pragma once
class Constants
{
public:
	Constants();
	~Constants();

	//Screen dimension constants
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;

	const int PLAYER_WIDTH = 64;
	const int PLAYER_HEIGTH = 64;

	const int FRAMES_RATE = 8;

	enum KeyPressDirection
	{
		KEY_PRESS_DIRECTION_DOWN,
		KEY_PRESS_DIRECTION_UP,
		KEY_PRESS_DIRECTION_LEFT,
		KEY_PRESS_DIRECTION_RIGHT,
		KEY_PRESS_DIRECTION_TOTAL,
		KEY_PRESS_DIRECTION_DEFAULT
	};
};


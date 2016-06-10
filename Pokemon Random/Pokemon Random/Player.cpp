#include "Player.h"


Player::Player(void)
{
	animation[ORIENTACION_ABAJO].loadSprite(animation[ORIENTACION_ABAJO].clips, "player/player_down_anim2.png");
	animation[ORIENTACION_ARRIBA].loadSprite(animation[ORIENTACION_ARRIBA].clips, "player/player_up_anim2.png");
	animation[ORIENTACION_IZQ].loadSprite(animation[ORIENTACION_IZQ].clips, "player/player_left_anim2.png");
	animation[ORIENTACION_DCHA].loadSprite(animation[ORIENTACION_DCHA].clips, "player/player_right_anim2.png");

	position.x = 0;
	position.y = 0;
}


Player::~Player(void)
{
}


void Player::move(int orientation)
{
	switch(orientation)
	{
		//El eje y está invertido
		case ORIENTACION_ABAJO:
			position.y += PLAYER_HEIGTH;
			break;
		case ORIENTACION_ARRIBA:
			position.y -= PLAYER_HEIGTH;
			break;
		case ORIENTACION_IZQ:
			position.x -= PLAYER_WIDTH;
			break;
		case ORIENTACION_DCHA:
			position.x += PLAYER_WIDTH;
			break;
		default:
			break;
	}
	animation[orientation].render(position, true);
}


void Player::stand(int orientation)
{
	animation[orientation].render(position);
}
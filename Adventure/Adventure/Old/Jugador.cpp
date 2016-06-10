#include "Jugador.h"

Jugador::Jugador(void)
{
	anim[ORIENTACION_ABAJO].spritHorizontal(anim[ORIENTACION_ABAJO].clips, "player/player_down_anim2.png");
	anim[ORIENTACION_ARRIBA].spritHorizontal(anim[ORIENTACION_ARRIBA].clips, "player/player_up_anim2.png");
	anim[ORIENTACION_IZQ].spritHorizontal(anim[ORIENTACION_IZQ].clips, "player/player_left_anim2.png");
	anim[ORIENTACION_DCHA].spritHorizontal(anim[ORIENTACION_DCHA].clips, "player/player_right_anim2.png");

	posicion.x = 0;
	posicion.y = 0;
}


Jugador::~Jugador(void)
{
}

void Jugador::mover(int orientacion)
{
	switch(orientacion)
	{
		//El eje y está invertido
		case ORIENTACION_ABAJO:
			posicion.y += PLAYER_HEIGTH;
			break;
		case ORIENTACION_ARRIBA:
			posicion.y -= PLAYER_HEIGTH;
			break;
		case ORIENTACION_IZQ:
			posicion.x -= PLAYER_WIDTH;
			break;
		case ORIENTACION_DCHA:
			posicion.x += PLAYER_WIDTH;
			break;
		default:
			break;
	}
	anim[orientacion].renderizar(posicion, true);
}


void Jugador::reposo(int orientacion)
{
	anim[orientacion].renderizar(posicion, false);
}
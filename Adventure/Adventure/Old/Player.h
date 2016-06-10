#pragma once

#include <SDL.h>
#include "Constantes.h"
#include "Texture.h"
#include "Animation.h"
#include "Vector2D.h"

class Player
{
public:
	Player(void);
	~Player(void);

	void move(int orientation);
	void stand(int orientation);

private:
	// Debe coincidir con KEY_PREESS. Indica hacia donde está mirando el personaje: 0 >> Abajo, 1 >> Arriba, 2 >> Izquiera, 3 >> Derecha
	enum orientacion 
	{
		ORIENTACION_ABAJO,
		ORIENTACION_ARRIBA,
		ORIENTACION_IZQ,
		ORIENTACION_DCHA,
		ORIENTACION_TOTAL
	};
	Vector2D position;
	Animation animation[ORIENTACION_TOTAL];
};



	


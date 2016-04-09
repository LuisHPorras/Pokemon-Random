#pragma once
#include <SDL.h>
#include "Constantes.h"
#include "Textura.h"
#include "Animacion.h"
#include "Vector2D.h"

class Jugador
{
public:
	Jugador(void);
	~Jugador(void);

	void mover(int orientacion);
	void reposo(int orientacion);

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
	Vector2D posicion;
	Animacion anim[ORIENTACION_TOTAL];
};


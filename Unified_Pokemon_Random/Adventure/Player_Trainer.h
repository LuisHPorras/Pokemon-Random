#pragma once

#include "Movable_Thing.h"

class Player_Trainer: public Movable_Thing
{
public:
	Player_Trainer(void);
	~Player_Trainer(void);

	void setRelPos(Vector2D pos);
	void swimmingRequest() { 42; }
private:

};






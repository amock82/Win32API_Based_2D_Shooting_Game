#pragma once

#include "Sprite.h"

class GameOver : public Sprite
{
private:

public:
	GameOver(float px, float py);
	virtual ~GameOver();

	virtual void start();
};
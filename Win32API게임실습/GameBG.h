#pragma once

#include "Sprite.h"

class GameBG : public Sprite
{
private:
public:
	GameBG(float px, float py);
	virtual ~GameBG();

	virtual void start();	
};

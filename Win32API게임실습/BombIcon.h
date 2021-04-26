#pragma once

#include "Sprite.h"

class BombIcon : public Sprite
{
private:

public:
	BombIcon(float px, float py);
	virtual ~BombIcon();

	virtual void start();
};
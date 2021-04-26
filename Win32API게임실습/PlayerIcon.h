#pragma once

#include "Sprite.h"

class PlayerIcon : public Sprite
{
private:

public:
	PlayerIcon(float px, float py);
	virtual ~PlayerIcon();

	virtual void start();
};
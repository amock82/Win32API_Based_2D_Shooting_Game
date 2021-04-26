#pragma once

#include "Sprite.h"

class EndingBG : public Sprite
{
private:

public:
	EndingBG(float px, float py);
	virtual ~EndingBG();

	virtual void start();
};
#pragma once

#include "Animation.h"

class BombExp : public Animation
{
private:
public:

	BombExp(float px, float py);
	virtual ~BombExp();

	virtual void start();
	virtual void animEndEvent();
};
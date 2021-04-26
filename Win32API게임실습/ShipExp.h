#pragma once

#include "Animation.h"

class ShipExp : public Animation
{
private:

public:
	ShipExp(float px, float py);
	virtual ~ShipExp();

	virtual void start();

	virtual void animEndEvent();
};
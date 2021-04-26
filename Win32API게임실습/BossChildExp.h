#pragma once

#include "Animation.h"

class BossChildExp : public Animation
{
private:

public:
	BossChildExp(float px, float py);
	virtual ~BossChildExp();

	virtual void start();
	virtual void animEndEvent();
};
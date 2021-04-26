#pragma once

#include "Animation.h"

class ReturnPlayer : public Animation
{
private:
	float speed;

public:
	ReturnPlayer(float px, float py);
	virtual ~ReturnPlayer();

	virtual void start();
	virtual void update();

	virtual void animEndEvent();
};
#pragma once

#include "Animation.h"

class PlayerBomb : public Animation
{
private:	
	
	float speed;

public:
	PlayerBomb(float px, float py);
	virtual ~PlayerBomb();

	virtual void start();
	virtual void update();
	virtual void animEndEvent();
};
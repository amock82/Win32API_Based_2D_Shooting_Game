#pragma once

#include "Sprite.h"

class DeadBoss : public Sprite
{
private:
	float speed;

public:
	DeadBoss(float px, float py);
	virtual ~DeadBoss();

	virtual void start();
	virtual void update();
};
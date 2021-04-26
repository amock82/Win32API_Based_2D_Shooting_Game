#pragma once

#include "Sprite.h"

class BombItem : public Sprite
{
private:
	float speed;
	float lifeTime;

public:
	BombItem(float px, float py);
	virtual ~BombItem();

	virtual void start();
	virtual void update();
};
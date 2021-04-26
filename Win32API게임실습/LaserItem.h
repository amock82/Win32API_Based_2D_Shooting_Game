#pragma once

#include "Sprite.h"

class LaserItem : public Sprite
{
private:
	float lifeTime;

public:
	LaserItem(float px, float py);
	virtual ~LaserItem();

	virtual void start();
	virtual void update();

	virtual void onTriggerStay(GameObject* other);
};
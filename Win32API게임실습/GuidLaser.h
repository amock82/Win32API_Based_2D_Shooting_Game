#pragma once

#include "Sprite.h"

class GuidLaser : public Sprite
{
private:
	float speed;
	float radian;

	float lifeTime;
public:
	GuidLaser(float px, float py, float angle);
	virtual ~GuidLaser();

	virtual void start();
	virtual void update();

	virtual void onTriggerStay(GameObject* other);

	void explode();
};
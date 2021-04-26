#pragma once

#include "Sprite.h"

class EnemyLaser : public Sprite
{
private:
	float speed;
	float lifeTime;

public:
	EnemyLaser(float px, float py);
	virtual ~EnemyLaser();

	virtual void start();
	virtual void update();

	virtual void onTriggerStay(GameObject* other);
};
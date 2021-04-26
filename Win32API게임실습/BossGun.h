#pragma once

#include "Sprite.h"

class BossGun : public Sprite
{
private:
	float hp;
	
public:
	BossGun(float px, float py, string name);
	virtual ~BossGun();

	virtual void start();
	virtual void onTriggerStay(GameObject* other);

	void fire();
};
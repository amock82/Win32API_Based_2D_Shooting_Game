#pragma once

#include "Sprite.h"

class WingGun : public Sprite
{
private:
	float hp;

public:
	WingGun(float px, float py, string name);
	virtual ~WingGun();

	virtual void start();
	virtual void onTriggerStay(GameObject* other);

	void fire();
};
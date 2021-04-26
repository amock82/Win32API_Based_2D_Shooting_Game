#pragma once

#include "Sprite.h"

class Radar : public Sprite
{
private:
	float hp;

public:
	Radar(float px, float py);
	virtual ~Radar();

	virtual void start();
	virtual void onTriggerStay(GameObject* other);
};
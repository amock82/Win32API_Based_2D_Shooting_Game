#pragma once

#include "Animation.h"

class Propeller : public Animation
{
private:
	float hp;

public:
	Propeller(float px, float py);
	virtual ~Propeller();

	virtual void start();
	virtual void onTriggerStay(GameObject* other);
};
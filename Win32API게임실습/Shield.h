#pragma once

#include "Animation.h"

class Shield : public Animation
{
private:

public:
	Shield(float px, float py);
	virtual ~Shield();

	virtual void start();
	virtual void onTriggerStay(GameObject* other);
};
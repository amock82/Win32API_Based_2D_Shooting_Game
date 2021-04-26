#pragma once

#include "GameObject.h"

class Shooter : public GameObject
{
private:
	enum class State{fire = 0, wait = 1};

	float fireTimer;
	float fireDelay;
	
	float fireStateTimer;
	float fireStateDelay;

	float waitStateTimer;
	float waitStateDelay;

	State state;

public:
	Shooter(float px, float py);
	virtual ~Shooter();

	virtual void update();

	virtual void onDrawGizmos();
};
#pragma once

#include "Sprite.h"

class Stealth : public Sprite
{
private:
	enum class State {showUp, attack, addShooter};

	float hp;
	float speed;
	float attackPos;

	State state;

public:
	Stealth(float px, float py);
	virtual ~Stealth();

	virtual void start();
	virtual void update();

	virtual void onTriggerStay(GameObject* other);

	void explode();
};
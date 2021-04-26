#pragma once

#include "Sprite.h"

#undef MAX_SIZE
#define MAX_SIZE 10

class Boss : public Sprite
{
private:
	enum class State { showUp, moveLeft, moveRight };

	float speed;

	float fireTimer;
	float fireDelay;

	int firePat[MAX_SIZE][9] = {
		{1,0,1,	0,	1,0,1,	0,0},
		{0,1,0,	1,	0,1,0,	1,1},
		{1,0,1,	0,	1,0,1,	0,0},
		{0,1,0,	1,	0,1,0,	1,1},
		{1,0,1,	0,	1,0,1,	0,0},

		{1,0,1,	0,	1,1,1,	1,1},
		{1,1,0,	1,	0,1,0,	1,1},
		{1,1,1,	0,	1,0,1,	1,1},
		{0,1,0,	1,	0,1,1,	1,1},
		{1,1,1,	0,	1,1,1,	0,0}
	};

	int fireIndex;

	State state;

public:
	Boss(float px, float py);
	virtual ~Boss();

	virtual void start();
	virtual void update();

	void explode();
	void checkDestroy();
	void fire();
};
#include "framework.h"

Shooter::Shooter(float px, float py) : GameObject("적기", "슈터", true, px, py)
{
	fireTimer = 0;
	fireDelay = 0.2f;

	this->fireStateTimer = 0;
	this->fireStateDelay = 3;

	this->waitStateTimer = 0;
	this->waitStateDelay = 3;

	this->state = State::fire;
}

Shooter::~Shooter(){}

void Shooter::update()
{
	if (state == State::fire)
	{
		fireTimer += Timer::deltaTime;

		if (fireTimer >= fireDelay)
		{
			float x = getPx();
			float y = getPy();

			float radius = 100;

			for (int i = 0; i < 10; i++)
			{
				float angle = i * 20;
				float radian = angle * M_PI / 180;

				float fx = x + cos(radian) * radius;
				float fy = y + sin(radian) * radius;

				ObjectManager::instantiate(new GuidLaser(fx, fy, angle), 0);
			}

			fireTimer = 0;
		}

		//발사샅애 시간 측정
		fireStateTimer += Timer::deltaTime;

		if (fireStateTimer >= fireStateDelay)
		{
			state = State::wait;
			fireStateTimer = 0;
		}
	}
	else if (state == State::wait)
	{
		waitStateTimer += Timer::deltaTime;

		if (waitStateTimer >= waitStateDelay)
		{
			state = State::fire;
			waitStateTimer = 0;
		}
	}
}

void Shooter::onDrawGizmos()
{
	float x = getPx();
	float y = getPy();

	drawLine(x - 20, y, x + 20, y, 100, 250, 250);
	drawLine(x, y - 20, x, y + 20, 100, 250, 250);
}
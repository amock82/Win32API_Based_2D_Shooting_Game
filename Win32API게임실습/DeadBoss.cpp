#include "framework.h"

DeadBoss::DeadBoss(float px, float py) : Sprite("적기", "데드보스", true, px, py)
{
	this->speed = 100;
}

DeadBoss::~DeadBoss(){}

void DeadBoss::start()
{
	setImage("Asset/적보스.bmp", 0, 613, 385, 182);
}

void DeadBoss::update()
{
	float dist = speed * Timer::deltaTime;

	translate(0, dist);

	if (getPy() >= 800)
	{
		ObjectManager::destroy(this);
	}
}
#include "framework.h"

BossGun::BossGun(float px, float py, string name) : Sprite("적기", name, true, px, py)
{
	this->hp = 100;
}

BossGun::~BossGun(){}

void BossGun::start()
{
	setImage("Asset/적보스.bmp", 426, 315, 20, 25);
	addBoxCollider2D(0, 2, 17, 15);
}

void BossGun::fire()
{
	float x = getPx();
	float y = getPy();

	ObjectManager::instantiate(new EnemyLaser(x, y + 5), 1);
}

void BossGun::onTriggerStay(GameObject* other)
{
	string tag = other->getTag();
	string name = other->getName();

	if (tag == "플레이어")
	{
		if (name == "레이저")
		{
			hp -= 10;

			if (hp <= 0)
			{
				float x = getPx();
				float y = getPy();

				ObjectManager::instantiate(new BossChildExp(x - 6.5, y - 6.5), 3);

				parent->delChildObj(this);
			}
		}
		else if (name == "폭탄폭발")
		{
			float x = getPx();
			float y = getPy();

			ObjectManager::instantiate(new BossChildExp(x - 6.5, y - 6.5), 3);

			parent->delChildObj(this);
		}
	}
}
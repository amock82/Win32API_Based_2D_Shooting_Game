#include "framework.h"

Radar::Radar(float px, float py) : Sprite("적기", "레이더", true, px, py)
{
	this->hp = 100;
}

Radar::~Radar(){}

void Radar::start()
{
	setImage("Asset/적보스.bmp", 360, 245, 11, 9);

	addBoxCollider2D(0, 0, 11, 9);
}

void Radar::onTriggerStay(GameObject* other)
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
			
				ObjectManager::instantiate(new BossChildExp(x - 9.5, y - 10.5), 3);

				parent->delChildObj(this);
			}
		}
		else if (name == "폭탄폭발")
		{
			float x = getPx();
			float y = getPy();

			ObjectManager::instantiate(new BossChildExp(x - 9.5, y - 10.5), 3);

			parent->delChildObj(this);
		}
	}
}
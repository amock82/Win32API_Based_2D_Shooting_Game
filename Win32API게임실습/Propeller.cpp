#include "framework.h"

Propeller::Propeller(float px, float py) : Animation("적기", "프로펠러", true, px, py)
{
	this->hp = 100;
}

Propeller::~Propeller(){}

void Propeller::start()
{
	//피해없는 애니매이션
	addImage("Asset/적보스.bmp", 7 + 34 * 0, 439, 32, 12, 0);
	addImage("Asset/적보스.bmp", 7 + 34 * 1, 439, 32, 12, 0);

	//피해있는 애니매이션
	addImage("Asset/적보스.bmp", 7 + 34 * 0, 455, 32, 52, 1);
	addImage("Asset/적보스.bmp", 7 + 34 * 1, 455, 32, 52, 1);

	//애니매이션 플레이
	play(0);

	//애니매이션 속도
	setSpeed(1.5);

	addBoxCollider2D(5, 0, 21, 12);
}

void Propeller::onTriggerStay(GameObject* other)
{
	string tag = other->getTag();
	string name = other->getName();

	if (tag == "플레이어")
	{
		if (name == "레이저")
		{
			hp -= 10;

			if (hp < 50)
			{
				play(1);
			}


			if (hp <= 0)
			{
				float x = getPx();
				float y = getPy();

				ObjectManager::instantiate(new BossChildExp(x + 1, y - 9), 3);

				parent->delChildObj(this);
			}
		}
		else if (name == "폭탄폭발")
		{
			float x = getPx();
			float y = getPy();

			ObjectManager::instantiate(new BossChildExp(x + 1, y - 9), 3);

			parent->delChildObj(this);
		}
	}
}
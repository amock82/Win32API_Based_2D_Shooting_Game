#include "framework.h"

Shield::Shield(float px, float py) : Animation("플레이어", "방패", true, px, py)
{

}

Shield::~Shield(){}

void Shield::start()
{
	addImage("Asset/보호방패1.bmp", 0);
	addImage("Asset/보호방패2.bmp", 0);
	addImage("Asset/보호방패3.bmp", 0);

	play(0);

	setSpeed(1.0f);

	// 충돌체 추가하기
	addBoxCollider2D(5, 5, 80, 80);
}

void Shield::onTriggerStay(GameObject* other)
{
	string tag = other->getTag();
	string name = other->getName();

	if (tag == "적기")
	{
		if (name == "아야코" || name == "스텔스" ||name == "보스")
		{
			parent->delChildObj(this);
		}
	}
}
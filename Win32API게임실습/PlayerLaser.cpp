#include "framework.h"

PlayerLaser::PlayerLaser(float px, float py)
		   :Sprite("플레이어", "레이저", true, px, py)
{
	this->speed    = 400;
	this->lifeTime = 10.0f;
}

PlayerLaser::~PlayerLaser()
{}

void PlayerLaser::start()
{
	setImage("Asset/레이저.bmp");
	addBoxCollider2D(0, 0, 6, 33);
}

void PlayerLaser::update()
{
	//이동//
	float dist = speed * Timer::deltaTime;
	translate(0, -dist);

	//라이프타임//
	lifeTime = lifeTime - Timer::deltaTime;

	if (lifeTime <= 0)
	{
		ObjectManager::destroy(this);
	}
}

void PlayerLaser::onTriggerStay(GameObject* other)
{
	string tag  = other->getTag();
	string name = other->getName();

	if (tag == "적기")
	{	
		if (name == "아야코" || name == "스텔스" || name == "레이더" || name.compare(0, 4, "윙건") == 0 || name == "날개" || name.compare(0, 6,"보스건") == 0 || name == "프로펠러")
		{
			//레이저 위치
			float x = getPx();
			float y = getPy();

			//폭발 객체를 풀에서 가져와서 활성화 시킴
			GameObject* exp = ObjectPool::pop("폭발효과", "레이저폭발");

			if (exp != nullptr)
			{
				//풀에서 가져온 객체 속성을 재설정
				exp->setPosition(x - 13, y - 10);
				exp->setActive(true);
			}
			else {
				cout << "레이저 폭발 객체가 풀에 없음" << endl;
			}

			//레이저 객체 제거
			ObjectManager::destroy(this);
		}
	}
}
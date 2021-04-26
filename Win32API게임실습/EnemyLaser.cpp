#include "framework.h"

EnemyLaser::EnemyLaser(float px, float py)
	       :Sprite("적기", "레이저", true, px, py)
{
	this->speed = 250;
	this->lifeTime = 10;
}

EnemyLaser::~EnemyLaser()
{}

void EnemyLaser::start()
{
	setImage("Asset/적기총알1.bmp");

	addBoxCollider2D(1, 0, 15, 15);
}

void EnemyLaser::update()
{
	// 이동
	float dist = speed * Timer::deltaTime;
	translate(0, dist);

	// 라이프타임
	lifeTime -= Timer::deltaTime;

	if (lifeTime <= 0)
	{
		ObjectManager::destroy(this);
	}
}

void EnemyLaser::onTriggerStay(GameObject* other)
{
	string tag = other->getTag();
	string name = other->getName();

	if (tag == "플레이어")
	{
		if (name == "팬텀" || name == "방패")
		{
			//레이저 위치
			float x = getPx();
			float y = getPy();

			//폭발 객체를 풀에서 가져와서 활성화 시킴
			GameObject* exp = ObjectPool::pop("폭발효과", "레이저폭발");

			if (exp != nullptr)
			{
				//풀에서 가져온 객체 속성을 재설정
				exp->setPosition(x - 8, y);
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
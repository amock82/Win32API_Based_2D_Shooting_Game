#include "framework.h"

Stealth::Stealth(float px, float py) : Sprite("적기", "스텔스", true, px, py)
{
	this->hp = 100;
	this->speed = 70;
	this->attackPos = 150;

	this->state = State::showUp;
}

Stealth::~Stealth(){}

void Stealth::start()
{
	setImage("Asset/적기2.bmp");

	addBoxCollider2D(46, 0, 36, 188);
	addBoxCollider2D(4, 29, 42, 65);
	addBoxCollider2D(82, 29, 42, 65);
	addBoxCollider2D(24, 94, 22, 54);
	addBoxCollider2D(82, 94, 22, 54);
}

void Stealth::update()
{
	//스테이트머신(FSM - Finite State Machine)
	if (state == State::showUp)
	{
		float dist = speed * Timer::deltaTime;

		translate(0, dist);

		if (getPy() >= attackPos)
		{
			state = State::addShooter;
		}
	}
	else if (state == State::addShooter)
	{
		//슈터 자식객체 추가
		addChildObj(new Shooter(58, 94), 1);
		state = State::attack;
	}
	else if (state == State::attack)
	{
		//필요시 공격중 행동패턴
	}
}

void Stealth::explode()
{
	float x = getPx();
	float y = getPy();

	//폭발 객체를 풀에서 가져와서 활성화 시킴
	GameObject* exp = ObjectPool::pop("폭발", "비행기폭발");

	if (exp != nullptr)
	{
		//풀에서 가져온 객체 속성을 재설정
		exp->setPosition(x - 40, y);
		exp->setActive(true);
	}
	else {
		cout << "기체 폭발 객체가 풀에 없음" << endl;
	}

	//스텔스 제거//
	ObjectManager::destroy(this);

	//스텔스 제거 카운트 증가
	GameManager::delStealthCount();

	//폭탄 아이템 생성하기
	ObjectManager::instantiate(new BombItem(x + 53, y + 74), 1);
}

void Stealth::onTriggerStay(GameObject* other)
{
	if (getAlive() == true)
	{

		string tag = other->getTag();
		string name = other->getName();

		if (tag == "플레이어")
		{
			if (name == "팬텀")
			{
				explode();
			}

			else if (name == "레이저")
			{
				//체력에...피해적용하기//
				hp = hp - 5;

				if (hp <= 0)
					explode();
			}

			else if (name == "폭탄폭발")
			{
				// 폭탄은 피해 상관없이 적기가 폭발됨
				explode();
			}
		}
	}
}
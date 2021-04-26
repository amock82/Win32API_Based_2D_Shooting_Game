#include "framework.h"

Ayako::Ayako(float px, float py, bool dropItem)
	  :Animation("적기", "아야코", true, px, py)
{
	this->speed = 70;
	this->fallFactor = 1.5f;
	this->hp    = 100;

	this->fireTimer = 0;
	this->fireDelay = 1.0f;

	this->lifeTime = 10;

	this->state = State::moveDown;

	this->dropItem = dropItem;
}

Ayako::~Ayako()
{}

void Ayako::start()
{
	//애니메이션 이미지로드(피해없는 애니메이션 클립) : 0 번//
	addImage("Asset/적기1.bmp", 1,   281, 190, 137,   0);
	addImage("Asset/적기1.bmp", 201, 281, 190, 137,   0);

	//애니메니션 이미지로드(중간피해 애니메이션 클립) : 1 번//
	addImage("Asset/적기1.bmp", 1 + 200 * 0, 141, 190, 137,  1);
	addImage("Asset/적기1.bmp", 1 + 200 * 1, 141, 190, 137,  1);
	addImage("Asset/적기1.bmp", 1 + 200 * 2, 141, 190, 137,  1);
	addImage("Asset/적기1.bmp", 1 + 200 * 3, 141, 190, 137,  1);

	//애니메니션 이미지로드(많은피해 애니메이션 클립) : 2 번//
	addImage("Asset/적기1.bmp", 1 + 200 * 0, 1, 190, 137, 2);
	addImage("Asset/적기1.bmp", 1 + 200 * 1, 1, 190, 137, 2);
	addImage("Asset/적기1.bmp", 1 + 200 * 2, 1, 190, 137, 2);
	addImage("Asset/적기1.bmp", 1 + 200 * 3, 1, 190, 137, 2);

	//충돌체 추가하기
	addBoxCollider2D(64, 10, 62,  14);
	addBoxCollider2D(87, 24, 16,  113);
	addBoxCollider2D(1,  88, 189, 17);

	//애니메이션 플레이 시작//
	play(0);
	setSpeed(2);

	// 좌우 이동 상태전환 높이 랜덤 범위 지정
	moveDownRange = Random::range(-100.0f, 100.0f);
}

void Ayako::update()
{
	// 행동 스테이트 머신
	switch (state)
	{
	case State::moveDown:
		moveDown();
		break;
	case State::moveLeft:
		moveLeft();
		break;
	case State::moveRight:
		moveRight();
		break;
	case State::fall:			
		fall();
		break;
	}

	// 발사
	fireTimer = fireTimer + Timer::deltaTime;

	if (fireTimer >= fireDelay)
	{
		float x = getPx();
		float y = getPy();

		ObjectManager::instantiate(new EnemyLaser(x + 86.5, y + 137));

		fireTimer = 0;
	}
}

void Ayako::explode()
{
	float x = getPx();
	float y = getPy();

	//폭발 객체를 풀에서 가져와서 활성화 시킴
	GameObject* exp = ObjectPool::pop("폭발", "비행기폭발");

	if (exp != nullptr)
	{
		//풀에서 가져온 객체 속성을 재설정
		exp->setPosition(x - 5, y);
		exp->setActive(true);
	}
	else {
		cout << "기체 폭발 객체가 풀에 없음" << endl;
	}

	//아야코 제거//
	ObjectManager::destroy(this);

	// 아야코 제거 카운트 증가
	GameManager::delAyakoCount();

	//레이저 아이템 생성하기
	//if(Random::range(0.0f, 1.0f) <= 0.5f)
	if(dropItem == true)
		ObjectManager::instantiate(new LaserItem(x + 95 - 11, y + 63), 1);
}

void Ayako::onTriggerStay(GameObject* other)
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
				hp = hp - 10;

				//아야코 피해 애니매이션 변경하기
				if (70 <= hp && hp <= 100)
					play(0);
				else if (40 <= hp && hp < 70)
					play(1);
				else
				{
					play(2);
					state = State::fall;
				}

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

void Ayako::moveDown()
{
	float dist = speed * Timer::deltaTime;
	translate(0, dist);

	if (getPy() >= 200 + moveDownRange)
	{
		float r = Random::range(0, 2);

		if (r == 0)
			state = State::moveLeft;
		else
			state = State::moveRight;
	}
}

void Ayako::moveLeft()
{
	float dist = speed * Timer::deltaTime;
	translate(-dist, 0);

	if (getPx() <= 20)
	{
		state = State::moveRight;
	}
}

void Ayako::moveRight()
{
	float dist = speed * Timer::deltaTime;
	translate(dist, 0);

	if (getPx() >= WIDTH - 190 - 20)
	{
		state = State::moveLeft;
	}
}

void Ayako::fall()
{
	float dist = fallFactor * speed * Timer::deltaTime;
	translate(0, dist);

	lifeTime -= Timer::deltaTime;

	if (lifeTime <= 0)
	{
		ObjectManager::destroy(this);

		// 아야코 제거 카운트 증가
		GameManager::delAyakoCount();
	}
}
#include "framework.h"

Boss::Boss(float px, float py) : Sprite("적기", "보스", true, px, py)
{
	this->speed = 50;

	this->fireTimer = 0;
	this->fireDelay = 0.8;

	this->fireIndex = 0;

	this->state = State::showUp;
}
	
Boss::~Boss(){}

void Boss::start()
{
	//폭발되지 않은 보스
	setImage("Asset/적보스.bmp", 0, 0, 493, 206);

	//프로펠러 자식
	addChildObj(new Propeller(63, 41), 2);
	addChildObj(new Propeller(111, 41), 2);
	addChildObj(new Propeller(159, 41), 2);

	addChildObj(new Propeller(302, 41), 2);
	addChildObj(new Propeller(350, 41), 2);
	addChildObj(new Propeller(398, 41), 2);

	//날개 자식 추가
	addChildObj(new Wing(256, 97, 0), 2);
	addChildObj(new Wing(302, 94, 1), 2);
	addChildObj(new Wing(350, 90, 2), 2);
	addChildObj(new Wing(405, 84, 3), 2);

	addChildObj(new Wing(206, 98, 4), 2);
	addChildObj(new Wing(158, 94, 5), 2);
	addChildObj(new Wing(110, 90, 6), 2);
	addChildObj(new Wing(62, 85, 7), 2);

	//보스건 추가
	addChildObj(new BossGun(94, 71, "보스건1"), 2);
	addChildObj(new BossGun(142, 71, "보스건2"), 2);
	addChildObj(new BossGun(190, 71, "보스건3"), 2);

	addChildObj(new BossGun(238, 63, "보스건4"), 2);

	addChildObj(new BossGun(286, 71, "보스건5"), 2);
	addChildObj(new BossGun(334, 71, "보스건6"), 2);
	addChildObj(new BossGun(382, 71, "보스건7"), 2);

	//윙건 추가
	addChildObj(new WingGun(265 + 5, 97 + 10, "윙건1"), 2);
	addChildObj(new WingGun(206 - 5, 97 + 10, "윙건2"), 2);

	//레이더 추가
	addChildObj(new Radar(241, 105), 2);
	addChildObj(new Radar(241, 117), 2);

	//보스 충돌체 추가
	addBoxCollider2D(227, 4, 39, 193);
	addBoxCollider2D(7, 60, 478, 32);
	addBoxCollider2D(185, 171, 123, 33);
	addBoxCollider2D(62, 92, 369, 13);
}

void Boss::update()
{
	if (state == State::showUp)
	{
		float dist = speed * Timer::deltaTime;
		translate(0, dist);

		if (getPy() >= 50)
		{
			state = State::moveLeft;
		}
	}
	else if (state == State::moveLeft)
	{
		float dist = speed * Timer::deltaTime;
		translate(-dist, 0);

		if (getPx() <= -106.5)
		{
			state = State::moveRight;
		}
	}
	else if (state == State::moveRight)
	{
		float dist = speed * Timer::deltaTime;
		translate(dist, 0);

		if (getPx() >= 93.5)
		{
			state = State::moveLeft;
		}
	}

	if (state != State::showUp)
	{
		checkDestroy();
		fire();
	}
}

void Boss::explode()
{
	float x = getPx();
	float y = getPy();

	//폭발 객체를 풀에서 가져와서 활성화 시킴
	/*GameObject* exp[6] = { ObjectPool::pop("폭발", "비행기폭발"),
						   ObjectPool::pop("폭발", "비행기폭발"),
						   ObjectPool::pop("폭발", "비행기폭발"),
						   ObjectPool::pop("폭발", "비행기폭발"),
						   ObjectPool::pop("폭발", "비행기폭발"),
						   ObjectPool::pop("폭발", "비행기폭발")};*/

	//폭발 위치 오프셋
	float offX[6] = { 0, 73, 146, 146 , 219 , 293 };
	float offY[6] = { -30, -20, -50 , 80 , -20, -30 };
	
	for (int i = 0; i < 6; i++)
	{
		GameObject* exp = ObjectPool::pop("폭발", "비행기폭발");
		if (exp != nullptr)
		{
			//풀에서 가져온 객체 속성을 재설정
			exp->setPosition(x + offX[i], y + offY[i]);
			exp->setActive(true);
		}
		else {
			cout << "기체 폭발 객체가 풀에 없음" << endl;
		}
	}

	//아야코 제거//
	ObjectManager::destroy(this);

	// 아야코 제거 카운트 증가
	GameManager::delAyakoCount();
}

void Boss::checkDestroy()
{
	if (getChildCount() <= 0)
	{
		float x = getPx();
		float y = getPy();

		//폭발효과
		explode();

		//DeadBoss객체 생성
		ObjectManager::instantiate(new DeadBoss(x + 47, y + 10), 1);

		//스테이지 클리어 변수 셋팅
		GameManager::setStageClear(true);

		//Boss객체 제거
		ObjectManager::destroy(this);
	}
}

void Boss::fire()
{
	fireTimer += Timer::deltaTime;

	if (fireTimer >= fireDelay)
	{
		string name[9] = { "보스건1", "보스건2", "보스건3", "보스건4", "보스건5", "보스건6", "보스건7" ,"윙건1", "윙건2" };

		for (int i = 0; i < 9; i++)
		{
			if (firePat[fireIndex][i] == 1)
			{
				//BossGun* gun = (BossGun*)find("보스건" + to_string(i+1));
				GameObject* gun = find(name[i]);

				if (gun != nullptr)
				{
					if (i < 7)
					{
						((BossGun*)gun)->fire();
					}
					else
					{
						((WingGun*)gun)->fire();
					}
				}
			}
		}

		fireIndex++;
		fireTimer = 0;

		if (fireIndex >= MAX_SIZE)
			fireIndex = 0;
	}
}
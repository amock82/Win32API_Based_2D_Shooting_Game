#include "framework.h"

EnemyManager::EnemyManager(float px, float py)
			:GameObject("", "", true, px, py)
{
	this->spawnTimer = 4.0f;
	this->spawnDelay = 5.0f;

	this->spawnIdx = 0;

	this->state = State::ayakoSpawn;
	this->stealthCount = 3;
}

EnemyManager::~EnemyManager(){}

void EnemyManager::update()
{
	if (state == State::ayakoSpawn)
	{
		spawnTimer += Timer::deltaTime;

		if (spawnTimer >= spawnDelay)
		{
			float x = getPx();
			float y = getPy();

			// 현재 화면상의 아야코 갯수 
			int ayakoCount = GameManager::getAyakoCount();

			if (ayakoCount < 5)
			{
				//왼쪽스폰
				if (spawnPat[spawnIdx][0] == 1)
				{
					ObjectManager::instantiate(new Ayako(x - 95 - 100, y - 137, false), 1);
					// 아야코 스폰 카운터 증가시키기
					GameManager::addAyakoCount();
				}
				//왼쪽스폰 + 아이템생성
				if (spawnPat[spawnIdx][0] == 2)
				{
					ObjectManager::instantiate(new Ayako(x - 95 - 100, y - 137, true), 1);
					// 아야코 스폰 카운터 증가시키기
					GameManager::addAyakoCount();
				}
				//오른쪽스폰
				if (spawnPat[spawnIdx][1] == 1)
				{
					ObjectManager::instantiate(new Ayako(x - 95 + 100, y - 137, false), 1);
					// 아야코 스폰 카운터 증가시키기
					GameManager::addAyakoCount();
				}
				//오른쪽스폰 + 아이템생성
				if (spawnPat[spawnIdx][1] == 2)
				{
					ObjectManager::instantiate(new Ayako(x - 95 + 100, y - 137, true), 1);
					// 아야코 스폰 카운터 증가시키기
					GameManager::addAyakoCount();
				}

				spawnTimer = 0;
				spawnDelay = Random::range(3.0f, 5.0f);

				spawnIdx++;

				if (spawnIdx >= MAX_SIZE)
				{
					state = State::stealthSpawn;	//스텔스 스폰 상태 전이(transition)
				}
			}
		}
	}
	else if (state == State::stealthSpawn)
	{
		if (GameManager::getStealthCount() <= 0)	//게임에 스텔스 적기가 없을 때
		{
			if (stealthCount > 0)
			{
				float x = getPx();
				float y = getPy();

				ObjectManager::instantiate(new Stealth(x - 60, y - 200), 1);
				GameManager::addStealthCount();	//현재까지 스폰해서 게임에 추가한 스텔스 갯수

				stealthCount--;	//남은 스폰갯수 감소
			}
			else
			{
				state = State::bossSpawn;
			}
		}
	}
	else if (state == State::bossSpawn)
	{
		float x = getPx();
		float y = getPy();

		ObjectManager::instantiate(new Boss(x - WIDTH/2 -6, y -250), 0);

		//에네미 매니저 제거
		ObjectManager::destroy(this);
	}
}

void EnemyManager::onDrawGizmos()
{
	float x = getPx();
	float y = getPy();
	 
	drawLine(x - 20, y, x + 20, y, 100, 250, 250);
	drawLine(x, y - 20, x, y + 20, 100, 250, 250);
}
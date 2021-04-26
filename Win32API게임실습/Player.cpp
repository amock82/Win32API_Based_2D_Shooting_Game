#include "framework.h"

Player::Player(float px, float py)
	  :Sprite("플레이어", "팬텀", true, px, py)
{
	this->state = State::showUp;
	this->speed = 300;

	this->fireTimer = 0;
	this->fireDelay = 0.15f;

	this->imageIdx   = 3;
	this->imageTimer = 0;
	this->imageDelay = 0.1f;

	this->shieldTimer = 2;

	this->laserCount = 1;
}

Player::~Player()
{
	//플레이어 이미지 배열..동적메모리 해제//
	for (int i = 0; i < 7; i++)
	{
		delete[] images[i].data;
	}
	
	resetImage();
}

void Player::start()
{
	//플레이어 이미지들 로드하기//
	readBMP("Asset/팬텀이동2.bmp", 64 * 0, 82, 62, 80, &images[0]);
	readBMP("Asset/팬텀이동2.bmp", 64 * 1, 82, 62, 80, &images[1]);
	readBMP("Asset/팬텀이동2.bmp", 64 * 2, 82, 62, 80, &images[2]);
	readBMP("Asset/팬텀이동2.bmp", 64 * 3, 82, 62, 80, &images[3]);
	readBMP("Asset/팬텀이동2.bmp", 64 * 4, 82, 62, 80, &images[4]);
	readBMP("Asset/팬텀이동2.bmp", 64 * 5, 82, 62, 80, &images[5]);
	readBMP("Asset/팬텀이동2.bmp", 64 * 6, 82, 62, 80, &images[6]);

	setImage(images[imageIdx]);

	//플레이어 충돌체 추가하기//	
	addBoxCollider2D(25, 7, 12, 66);	
	addBoxCollider2D(9, 41, 44, 14);
	
	//방패 자식객체 추가하기//
	addChildObj(new Shield(-14, -5), 1);
}

void Player::update()
{
	if (GameManager::isPause == false)
	{
		if (state == State::showUp)
		{
			showUp();
		}
		else if (state == State::control)
		{
			move();
			fire();
			shield();
			stageClear();
		}
	}
}

void Player::showUp()
{
	float dist = speed / 1.5f * Timer::deltaTime;
	translate(0, -dist);

	if (getPy() <= HEIGHT - 200)
	{
		state = State::control;
	}
}

void Player::move()
{
	//플레이어 이동//
	float dist = speed * Timer::deltaTime;

	if (Input::getKey("left") == true)
	{
		translate(-dist, 0);

		if (getPx() < 0)
		{
			setPx(0);
		}

		//이미지 변경하기//
		if (imageIdx > 0)
		{
			imageTimer = imageTimer + Timer::deltaTime;

			if (imageTimer >= imageDelay)
			{
				imageIdx--;
				setImage(images[imageIdx]);

				imageTimer = 0;
			}
		}
	}

	if (Input::getKey("right") == true)
	{
		translate(dist, 0);

		if (getPx() > WIDTH - 62)
		{
			setPx(WIDTH - 62);
		}

		//이미지 변경하기
		if (imageIdx < 6)
		{
			imageTimer = imageTimer + Timer::deltaTime;

			if (imageTimer >= imageDelay)
			{
				imageIdx++;
				setImage(images[imageIdx]);

				imageTimer = 0;
			}
		}
	}

	if (Input::getKey("up") == true)
	{
		translate(0, -dist);

		if (getPy() < 0)
		{
			setPy(0);
		}
	}

	if (Input::getKey("down") == true)
	{
		translate(0, dist);

		if (getPy() > HEIGHT - 86)
		{
			setPy(HEIGHT - 86);
		}
	}

	//플레이어가 좌우이동이 아닌경우
	if (Input::getKey("left") == false && Input::getKey("right") == false)
	{
		if (imageIdx != 3)
		{
			imageTimer = imageTimer + Timer::deltaTime;

			if (imageTimer >= imageDelay)
			{
				if (imageIdx < 3)
				{
					imageIdx++;
				}
				else {
					imageIdx--;
				}

				setImage(images[imageIdx]);
				imageTimer = 0;
			}
		}
	}
}

void Player::fire()
{
	//레이저 발사//
	if (GetAsyncKeyState(VK_SPACE) != 0)
	{
		//발사시간측정하기
		fireTimer = fireTimer + Timer::deltaTime;

		if (fireTimer >= fireDelay)
		{
			//발사위치
			//float x = getPx();
			//float y = getPy();

			float x, y;
			getPosition(x, y);

			//레이저 발사//
			if (laserCount == 1)
			{
				ObjectManager::instantiate(new PlayerLaser(x + 29, y - 25));
			}
			else if(laserCount == 2)
			{
				ObjectManager::instantiate(new PlayerLaser(x + 19, y - 25));
				ObjectManager::instantiate(new PlayerLaser(x + 39, y - 25));
			}
			else if (laserCount == 3)
			{
				ObjectManager::instantiate(new PlayerLaser(x + 9, y - 25));
				ObjectManager::instantiate(new PlayerLaser(x + 29, y - 45));
				ObjectManager::instantiate(new PlayerLaser(x + 49, y - 25));
			}

			//타이머 리셋하기
			fireTimer = 0;
		}
	}

	//폭탄 발사하기//
	if (Input::getKeyDown("z")==true)
	{
		if (GameManager::getBombCount() > 0)
		{
			float x, y;
			getPosition(x, y);

			//폭탄 발사//
			ObjectManager::instantiate(new PlayerBomb(x + 15, y - 2));

			GameManager::subBombCount();
		}
		else
			cout << "남아있는 폭탄이 없음" << endl;
	}
}

void Player::shield()
{
	//실드 타이머 
	shieldTimer -= Timer::deltaTime;

	if (shieldTimer <= 0)
	{
		//숨기기
		//getChild(0)->setActive(false);
		//find("방패")->setActive(false);

		//방패 제거하기
		GameObject* obj = getChild(0);

		if (obj != nullptr)
		{
			delChildObj(obj);
		}
	}
}

void Player::stageClear()
{
	if (GameManager::getStageClear() == true)
	{
		float x = getPx();
		float y = getPy();

		ObjectManager::instantiate(new ReturnPlayer(x, y), 3);

		ObjectManager::destroy(this);
	}
}

void Player::explode()
{
	if (getAlive() == true)
	{
		// 플레이어 폭발효과
		GameObject* exp = ObjectPool::pop("폭발", "비행기폭발");

		if (exp != nullptr)
		{
			float x = getPx();
			float y = getPy();

			exp->setPosition(x - 60, y - 50);
			exp->setActive(true);
		}
		else {
			cout << "기체 폭발 객체가 풀에 없음" << endl;
		}

		// 플레이어 제거
		ObjectManager::destroy(this);

		//플레이어 리스폰
		GameManager::restartPlayer();
	}
}

void Player::onTriggerStay(GameObject* other)
{
	string tag  = other->getTag();
	string name = other->getName();

	if (tag == "적기")
	{
		if (getAlive() == true)
		{
			if (name == "아야코" || name == "스텔스" || name == "보스")
			{
				explode();
			}
			else if (name == "레이저")
			{
				GameManager::damagePlayer(20);
			}
			else if (name == "유도레이저")
			{
				GameManager::damagePlayer(2);
			}
		}
	}

	if (tag == "아이템")
	{
		if (name == "레이저")
		{
			if (other->getAlive() == true)
			{
				laserCount++;

				if (laserCount > 3)
				{
					laserCount = 3;
				}

				ObjectManager::destroy(other);
			}
		}
		else if (name == "폭탄")
		{
			if (other->getAlive() == true)
			{
				GameManager::addBombCount();

				ObjectManager::destroy(other);
			}
		}
	}
}
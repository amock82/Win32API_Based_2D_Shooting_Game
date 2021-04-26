#include "framework.h"

int GameManager::ayakoSpawnCount = 0;
int GameManager::ayakoDelCount = 0;

int GameManager::stealthSpawnCount = 0;
int GameManager::stealthDelCount = 0;

int GameManager::playerCount = 3;
float GameManager::playerHP = 100;

bool GameManager::stageClear = false;

GameObject* GameManager::playerIcon[3] = { nullptr, nullptr, nullptr };
GameObject* GameManager::playerObj = nullptr;
GameObject* GameManager::playerHPBar = nullptr;

GameObject* GameManager::bombIcon[5] = { nullptr, nullptr, nullptr, nullptr, nullptr };

int GameManager::bombCount = 3;

bool GameManager::isPause = false;

void GameManager::init()
{
	//게임 변수 초기화
	ayakoSpawnCount = 0;
	ayakoDelCount = 0;

	stealthSpawnCount = 0;
	stealthDelCount = 0;

	playerCount = 3;
	playerHP = 100;

	stageClear = false;

	bombCount = 3;

	isPause = false;
	Timer::timeScale = 1.0f;

	//플레이어 아이콘 출력
	playerIcon[0] = ObjectManager::instantiate(new PlayerIcon(360, 730), 5);
	playerIcon[1] = ObjectManager::instantiate(new PlayerIcon(400, 730), 5);
	playerIcon[2] = ObjectManager::instantiate(new PlayerIcon(440, 730), 5);

	//플레이어 체력바 출력
	playerHPBar = ObjectManager::instantiate(new HPBar(20, 20), 5);

	showHPBar();

	//폭탄아이콘 출력
	bombIcon[0] = ObjectManager::instantiate(new BombIcon(20, 750), 5);
	bombIcon[1] = ObjectManager::instantiate(new BombIcon(50, 750), 5);
	bombIcon[2] = ObjectManager::instantiate(new BombIcon(80, 750), 5);
	bombIcon[3] = ObjectManager::instantiate(new BombIcon(110, 750), 5);
	bombIcon[4] = ObjectManager::instantiate(new BombIcon(140, 750), 5);

	showBombIcon();

	//버튼 추가
	//ObjectManager::instantiate(new Button(240 - 106, 400 - 18), 5);
	ObjectManager::instantiate(new BTNExit(420, 10), 5);
	ObjectManager::instantiate(new BTNPause(420 - 60, 10), 5);

	//메뉴 추가
	ObjectManager::instantiate(new Menu(240 - 245 / 2, 200), 6);
}

void GameManager::addAyakoCount()
{
	ayakoSpawnCount++;
}

void GameManager::delAyakoCount()
{
	ayakoDelCount++;
}

int GameManager::getAyakoCount()
{
	return ayakoSpawnCount - ayakoDelCount;
}

void GameManager::addStealthCount()
{
	stealthSpawnCount++;
}

void GameManager::delStealthCount()
{
	stealthDelCount++;
}

int GameManager::getStealthCount()
{
	return stealthSpawnCount - stealthDelCount;
}

void GameManager::setStageClear(bool clear)
{
	stageClear = clear;
}

bool GameManager::getStageClear()
{
	return stageClear;
}

void GameManager::restartPlayer()
{
	if (playerCount > 0)
	{
		//플레이어 리스폰
		playerObj = ObjectManager::instantiate(new Player(WIDTH / 2 - 31, HEIGHT + 100), 3);

		playerCount--;

		playerIcon[playerCount]->setActive(false);

		//체력회복
		playerHP = 100;

		//체력 출력
		showHPBar();
	}
	else
	{
		ObjectManager::instantiate(new GameOver(30, 200), 5);
	}
}

void GameManager::damagePlayer(float damage)
{
	playerHP -= damage;

	//체력바 출력
	showHPBar();

	//((HPBar*)playerHPBar)->setFillAmount(playerHP / 100.0f);

	if (playerHP <= 0)
	{
		//플레이어 폭발시킴
		((Player*)playerObj)->explode();
	}
}

void GameManager::showHPBar()
{
	HPBar* bar = (HPBar*)playerHPBar;
	bar->setFillAmount(playerHP / 100.0f);
}

int GameManager::getBombCount()
{
	return bombCount;
}

void GameManager::addBombCount()
{
	bombCount++;

	if (bombCount > 5)
		bombCount = 5;

	showBombIcon();
}

void GameManager::subBombCount()
{
	bombCount--;
	showBombIcon();
}

void GameManager::showBombIcon()
{
	for (int i = 0; i < 5; i++)
	{
		if (i < bombCount)
		{
			bombIcon[i]->setActive(true);
		}
		else
		{
			bombIcon[i]->setActive(false);
		}
	}
}
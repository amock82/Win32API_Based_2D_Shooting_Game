#include "framework.h"

PlayerBomb::PlayerBomb(float px, float py)
	      :Animation("ÇÃ·¹ÀÌ¾î", "ÆøÅº", true, px, py)
{
	this->speed = 80;
}

PlayerBomb::~PlayerBomb()
{}

void PlayerBomb::start()
{
	for (int i = 0; i < 8; i++)
	{
		addImage("Asset/ÆÒÅÒÆøÅº2.bmp", i * 34, 0, 32, 32, 0);
	}

	//¾Ö´Ï¸ÞÀÌ¼Ç ¼Óµµ//
	setSpeed(0.5);
}

void PlayerBomb::update()
{
	float dist = speed * Timer::deltaTime;
	translate(0, -dist);
}

void PlayerBomb::animEndEvent()
{
	//ÆøÅº Æø¹ß È¿°ú
	float x = getPx();
	float y = getPy();

	ObjectManager::instantiate(new BombExp(x - 48, y - 48));

	//ÆøÅº °´Ã¼ Á¦°Å
	ObjectManager::destroy(this);
}
#include "framework.h"

ReturnPlayer::ReturnPlayer(float px, float py) 
			: Animation("ÇÃ·¹ÀÌ¾î", "¸®ÅÏÇÃ·¹ÀÌ¾î", true, px, py)
{
	this->speed = 150;
}

ReturnPlayer::~ReturnPlayer(){}

void ReturnPlayer::start()
{
	for (int i = 0; i < 7; i++)
	{
		addImage("Asset/ÆÒÅÒ±ÍÈ¯.bmp", 64 * i, 0, 62, 240, 0);
	}
	addImage("Asset/ÆÒÅÒ±ÍÈ¯.bmp", 64 * 7, 0, 62, 240, 1);
	addImage("Asset/ÆÒÅÒ±ÍÈ¯.bmp", 64 * 8, 0, 62, 240, 1);
	addImage("Asset/ÆÒÅÒ±ÍÈ¯.bmp", 64 * 9, 0, 62, 240, 1);

	setSpeed(0.7);
}

void ReturnPlayer::update()
{
	float dist = speed * Timer::deltaTime;
	translate(0, -dist);

	if (getPy() <= -240)
	{
		ObjectManager::destroy(this);

		SceneManager::loadScene(new EndingScene());
	}
}

void ReturnPlayer::animEndEvent()
{
	speed = 400;

	play(1);
}
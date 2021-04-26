#include "framework.h"

GameOver::GameOver(float px, float py) : Sprite("UI", "게임오버", true, px, py)
{

}

GameOver::~GameOver(){}

void GameOver::start()
{
	setImage("Asset/게임오버.bmp");
}
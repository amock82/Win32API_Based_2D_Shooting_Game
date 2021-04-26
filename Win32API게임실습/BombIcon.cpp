#include "framework.h"

BombIcon::BombIcon(float px, float py) : Sprite("UI", "气藕酒捞能", true, px, py)
{

}

BombIcon::~BombIcon(){}

void BombIcon::start()
{
	setImage("Asset/UI/气藕酒捞能.bmp");
}
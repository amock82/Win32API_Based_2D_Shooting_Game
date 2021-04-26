#include "framework.h"

PlayerIcon::PlayerIcon(float px, float py) : Sprite("UI", "플레이어아이콘", true, px, py)
{

}

PlayerIcon::~PlayerIcon(){}

void PlayerIcon::start()
{
	setImage("Asset/UI/팬텀이미지.bmp");
}
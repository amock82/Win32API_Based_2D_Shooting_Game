#include "framework.h"

GameBG::GameBG(float px, float py) 
	   : Sprite("배경", "게임배경", true, px, py)
{}

GameBG::~GameBG()
{}

void GameBG::start()
{
	//스플라이트 이미지 로드//
	setImage("Asset/배경1.bmp");
}
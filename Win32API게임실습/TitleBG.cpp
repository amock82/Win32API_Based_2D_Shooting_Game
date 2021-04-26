#include "framework.h"

TitleBG::TitleBG(float px, float py) : Sprite("배경", "타이틀배경", true, px, py)
{}

TitleBG::~TitleBG(){}

void TitleBG::start()
{
	setImage("Asset/타이틀배경2.bmp");
}
#include "framework.h"

EndingBG::EndingBG(float px, float py) : Sprite("배경", "엔딩배경", true, px, py)
{

}

EndingBG::~EndingBG(){}

void EndingBG::start() 
{
	setImage("Asset/엔딩배경.bmp");
}
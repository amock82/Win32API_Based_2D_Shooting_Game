#include "framework.h"

LaserExp::LaserExp(float px, float py) 
	:Animation("폭발효과", "레이저폭발", true, px, py)
{}

LaserExp::~LaserExp()
{}

void LaserExp::start()
{
	//애니메이션 추가하기//
	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < 5; i++)
		{
			addImage("Asset/레이저폭발.bmp", 36 * i, 36 * j, 36, 36, 0);
		}
	}	

	//애니메이션 플레이
	play(0);

	//애니메이션 속도
	setSpeed(5);
}

//애님종류 이벤 오버라이딩//
void LaserExp::animEndEvent()
{
	this->setActive(false);
}
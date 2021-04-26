#include "framework.h"

BombExp::BombExp(float px, float py)
	   :Animation("플레이어", "폭탄폭발", true, px, py)
{}

BombExp::~BombExp()
{}

void BombExp::start()
{
	//애니메이션 이미지 추가//
	for (int j = 0; j < 2; j++)
	{
		for (int i = 0; i < 6; i++)
		{
			addImage("Asset/팬텀폭탄폭발.bmp", i * 130, j * 130, 128, 128, 0);
		}
	}

	//애니메니션 재생
	play(0);	

	//애니메이션 속도
	setSpeed(2);

	// 충돌체 추가하기
	addBoxCollider2D(10, 10, 108, 108);
}

void BombExp::animEndEvent()
{
	ObjectManager::destroy(this);
}
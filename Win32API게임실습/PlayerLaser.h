#pragma once

#include "Sprite.h"

class PlayerLaser : public Sprite
{
private:

	float speed;
	float lifeTime;  //객체가 살아있는 시간

public:
	PlayerLaser(float px, float py);
	virtual ~PlayerLaser();

	virtual void start();
	virtual void update();

	//충돌이벤트 오버라이딩//
	virtual void onTriggerStay(GameObject* other);	
};
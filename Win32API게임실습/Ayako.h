#pragma once

#include "Animation.h"

class Ayako : public Animation
{
private:
	enum class State
	{
		moveDown,
		moveLeft,
		moveRight,
		fall
	};

	float speed;
	float fallFactor;
	float hp;

	float fireTimer;
	float fireDelay;

	float lifeTime;
	float moveDownRange;

	State state;	

	bool dropItem;

public:
	Ayako(float px, float py, bool dropItem);
	~Ayako();

	virtual void start();
	virtual void update();

	//충돌 이벤트 함수 오버라이딩//
	virtual void onTriggerStay(GameObject* other);

	//아야코 폭발 함수
	void explode();

	// 상태 동작함수
	void moveDown();
	void moveLeft();
	void moveRight();
	void fall();
};

#pragma once

#include "Sprite.h"

class Player : public Sprite
{
private:

	enum class State {showUp, control};

	//상태변수
	State state;

	//이동속도
	float speed;

	//발사타이머//
	float fireTimer;
	float fireDelay;

	//플레이어 이미지 저장 배열//
	Image images[7];
	int   imageIdx;  

	//이미지 타이머
	float imageTimer;
	float imageDelay;

	//실드 타이머
	float shieldTimer;

	//플레이어 체력
	//float hp;	//GameManager로 이동

	//레이저 발사 갯수
	int laserCount;

	//폭탄 갯수
	//int bombCount;	//GameManager로 이동함

public:
	Player(float px, float py);
	virtual ~Player();

	virtual void start();
	virtual void update();

	//플레이어 등장함수
	void showUp();

	//이동함수
	void move();

	//발사함수
	void fire();

	//플레이어 쉴드함수
	void shield();

	//스테이지 클리어 체크 함수
	void stageClear();

	//충돌이벤트 오버라이딩//
	virtual void onTriggerStay(GameObject* other);

	//플레이어 폭발함수
	void explode();
};

#pragma once

#include <vector>
#include "Sprite.h"

using namespace std;

class Animation : public Sprite
{
private:
		
	vector<Image> images[10];
	
	int imageIdx;
	int animClip;

	//이미지 타이머
	float imageTimer;
	float imageDelay;

	//애니메이션속도
	float animSpeed;

public:

	Animation(string tag, string name, bool active, float px, float py);
	virtual ~Animation();
	
	virtual void draw();

	//애니메이션 이미지들 추가하기//
	void addImage(string fileName, int x, int y, int width, int height, int animClip);
	void addImage(string fileName, int animClip);

	//애니메이션 플레이함수
	void play(int animClip);

	//애니메이션 속도 함수//
	void setSpeed(float speed);  //1.0f는 현재속도임

	//애니메션 종료 이벤트//
	virtual void animEndEvent();
};

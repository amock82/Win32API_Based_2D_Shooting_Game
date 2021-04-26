#pragma once

#include "Sprite.h"

class Button : public Sprite
{
private:
	enum class State { normal, hover, press, release, click};

	State state;

	bool isUsed;

public:
	Button(float px, float py);
	virtual ~Button();

	virtual void update();

	//마우스 포인터가 버튼 이미지 영역안에 있는지 검사하는 함수
	bool mouseInButton();
	void checkClick();
	virtual void onClick();
};
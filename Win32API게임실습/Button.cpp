#include "framework.h"

Button::Button(float px, float py) : Sprite("UI", "버튼", true, px, py)
{
	this->state = State::normal;
	this->isUsed = true;
}

Button::~Button(){}

void Button::update()
{
	if (getActive())
	{
		checkClick();
	}
}

bool Button::mouseInButton()
{
	//버튼 이미지 사각형 좌표
	float a = getPx();
	float b = getPy();
	float c = a + getImageWidth();
	float d = b + getImageHeight();

	//마우스 좌표 변수
	float x = Input::mousePosition.x;
	float y = Input::mousePosition.y;

	if (a <= x && x <= c && b <= y && y <= d)
		return true;
	else
		return false;
}

void Button::checkClick()
{
	if (isUsed == true)
	{
		if (state == State::normal)
		{
			if (mouseInButton() == true)
			{
				state = State::hover;
			}
		}
		else if (state == State::hover)
		{
			if (Input::getMouseButtonDown(0) == true)
			{
				state = State::press;

				translate(1, 1);
			}
			else if (mouseInButton() == false)
			{
				state = State::normal;
			}
		}
		else if (state == State::press)
		{
			if (Input::getMouseButtonUp(0) == true)
			{
				state = State::release;

				translate(-1, -1);
			}
		}
		else if (state == State::release)
		{
			if (mouseInButton() == true)
			{
				state = State::click;
			}
			else
			{
				state = State::normal;
			}
		}
		else if (state == State::click)
		{
			// 원하는 동작
			onClick();

			state = State::normal;
		}
	}
}

void Button::onClick()
{
	
}
#include "framework.h"

Animation::Animation(string tag, string name, bool active, float px, float py)
	     :Sprite(tag, name, active, px, py)
{
	this->imageIdx   = 0;
	this->imageTimer = 0;
	this->imageDelay = 0.1f;
	this->animClip   = 0;
	this->animSpeed  = 1.0f;
}

Animation::~Animation()
{
	for (int clip = 0; clip < 10; clip++)
	{
		for (int i = 0; i < images[0].size(); i++)
		{
			delete[] images[clip][i].data;
		}

		images[clip].clear();
	}

	resetImage(); //부모 클래스 Sprite의 포인터 리셋
}

void Animation::draw()
{
	if (getActive() == true)
	{
		//스프라이트 부모클래스 draw 호출하기//
		Sprite::draw();

		//애니메이션 출력 스플라이트 변경하기//
		imageTimer = imageTimer + Timer::deltaTime;

		if (imageTimer >= imageDelay / animSpeed)
		{
			imageIdx++;

			if (imageIdx >= images[animClip].size())
			{
				//애니메니션 1회 종료 이벤트//
				animEndEvent();

				imageIdx = 0;
			}

			setImage(images[animClip][imageIdx]);
			imageTimer = 0;
		}
	}
}

void Animation::addImage(string fileName, int x, int y, int width, int height, int animClip)
{
	Image img;
	
	readBMP(fileName.data(), x, y, width, height, &img);
	images[animClip].push_back(img);
}

void Animation::addImage(string fileName, int animClip)
{
	Image img;

	readBMP(fileName.data(), &img);
	images[animClip].push_back(img);
}

void Animation::play(int animClip)
{
	setImage(images[animClip][imageIdx]);
	this->animClip = animClip;
}

void Animation::setSpeed(float speed)  //1.0f는 현재속도임
{
	animSpeed = speed;
}

void Animation::animEndEvent()
{}
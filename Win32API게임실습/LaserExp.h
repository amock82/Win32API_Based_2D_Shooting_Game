#pragma once

#include "Animation.h"

class LaserExp : public Animation
{
private:
public:

	LaserExp(float px, float py);
	virtual ~LaserExp();

	virtual void start();

	//애님종류 이벤 오버라이딩//
	virtual void animEndEvent();
};
#include "framework.h"

float Timer::currTime;
float Timer::prevTime;
float Timer::deltaTime;
float Timer::timeScale;

void Timer::init()
{
	//시간측정하기 - GetTickCount는 컴퓨터가 부팅이후의 시간을 ms 단위로..카운트함//
	currTime = GetTickCount() / 1000.0f;
	prevTime = GetTickCount() / 1000.0f;
	deltaTime = 0;
	timeScale = 1;
}

void Timer::update()
{
	//업데이트//
	currTime = GetTickCount() / 1000.0f;
	deltaTime = (currTime - prevTime) * timeScale;
	prevTime = currTime;
}
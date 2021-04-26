#pragma once

class Timer
{
private:
	static float currTime;
	static float prevTime;	

public:
	static float deltaTime;
	static float timeScale;

	static void init();
	static void update();	
};


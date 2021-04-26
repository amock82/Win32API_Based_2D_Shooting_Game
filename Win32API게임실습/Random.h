#pragma once

class Random
{
private:

public:
	static void init();

	static float range(float min, float max);
	static int range(int min, int max);
};
#include "framework.h"

void Random::init()
{
	srand(time(nullptr));
}

float Random::range(float min, float max)
{
	return (rand() / (float)RAND_MAX) * (max - min) + min;
}

int Random::range(int min, int max)
{
	return rand() % (max - min) + min;
}
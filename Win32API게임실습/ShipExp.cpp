#include "framework.h"

ShipExp::ShipExp(float px, float py) 
		:Animation("气惯", "厚青扁气惯", true, px, py)
{

}

ShipExp::~ShipExp()
{

}

void ShipExp::start()
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			addImage("Asset/利扁气惯.bmp", 200 * j, 200 * i, 200, 200, 0);
		}
	}

	play(0);

	setSpeed(3);
}

void ShipExp::animEndEvent()
{
	this->setActive(false);
}
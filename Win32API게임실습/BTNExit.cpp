#include "framework.h"

BTNExit::BTNExit(float px, float py) : Button(px, py)
{

}

BTNExit::~BTNExit(){}

void BTNExit::start()
{
	setImage("Asset/UI/btnExit.bmp");
}

void BTNExit::onClick()
{
	Application::quit();
}
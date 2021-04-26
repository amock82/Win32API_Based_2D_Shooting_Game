#include "framework.h"

//////////////////////////////
//		시작 버튼 클래스		//
//////////////////////////////
BtnStart::BtnStart(float px, float py) : Button(px, py)
{

}

BtnStart::~BtnStart(){}

void BtnStart::start()
{
	setImage("Asset/UI/시작버튼.bmp");
}

void BtnStart::onClick()
{
	SceneManager::loadScene(new GameScene());
}


//////////////////////////////
//		모드 버튼 클래스		//
//////////////////////////////
BtnMode::BtnMode(float px, float py) : Button(px, py)
{

}

BtnMode::~BtnMode() {}

void BtnMode::start()
{
	setImage("Asset/UI/모드선택.bmp");
}

void BtnMode::onClick()
{
	cout << "모드선택 버튼" << endl;
}


//////////////////////////////
//		옵션 버튼 클래스		//
//////////////////////////////
BtnOption::BtnOption(float px, float py) : Button(px, py)
{

}

BtnOption::~BtnOption() {}

void BtnOption::start()
{
	setImage("Asset/UI/옵션설정.bmp");
}

void BtnOption::onClick()
{
	cout << "옵션 버튼" << endl;
}



//////////////////////////////
//		종료 버튼 클래스		//
//////////////////////////////
BtnQuit::BtnQuit(float px, float py) : Button(px, py)
{

}

BtnQuit::~BtnQuit() {}

void BtnQuit::start()
{
	setImage("Asset/UI/끝내기.bmp");
}

void BtnQuit::onClick()
{
	Application::quit();
}
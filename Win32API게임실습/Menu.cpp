#include "framework.h"

//////////////////////////
//		메뉴 클래스		//
//////////////////////////
Menu::Menu(float px, float py) : Sprite("UI", "메뉴", true, px, py)
{

}

Menu::~Menu(){}

void Menu::start()
{
	setImage("Asset/UI/menu.bmp");

	addChildObj(new ItemResume(16, 19), 6);
	addChildObj(new ItemRestart(16, 19 + 38), 6);
	addChildObj(new ItemMain(16, 19 + 76), 6);
	addChildObj(new ItemExit(16, 19 + 114), 6);
	
	this->setActive(false);
}


//////////////////////////////////
//		이어하기 버튼 클래스		//
//////////////////////////////////
ItemResume::ItemResume(float px, float py) : Button(px, py)
{

}

ItemResume::~ItemResume(){}

void ItemResume::start()
{
	setImage("Asset/UI/itemResume.bmp");
}

void ItemResume::onClick()
{
	Timer::timeScale = 1.0f;		//게임진행
	GameManager::isPause = false;	//정지변수 세팅
	
	parent->setActive(false);		//메뉴숨김
}

//////////////////////////////////
//		다시하기 버튼 클래스		//
//////////////////////////////////
ItemRestart::ItemRestart(float px, float py) : Button(px, py)
{

}

ItemRestart::~ItemRestart() {}

void ItemRestart::start()
{
	setImage("Asset/UI/ItemRestart.bmp");
}

void ItemRestart::onClick()
{
	SceneManager::loadScene(new GameScene());
}

//////////////////////////////////
//		메인으로 버튼 클래스		//
//////////////////////////////////
ItemMain::ItemMain(float px, float py) : Button(px, py)
{

}

ItemMain::~ItemMain() {}

void ItemMain::start()
{
	setImage("Asset/UI/ItemMain.bmp");
}

void ItemMain::onClick()
{
	SceneManager::loadScene(new TitleScene());
}

//////////////////////////////////
//		게임종료 버튼 클래스		//
//////////////////////////////////
ItemExit::ItemExit(float px, float py) : Button(px, py)
{

}

ItemExit::~ItemExit() {}

void ItemExit::start()
{
	setImage("Asset/UI/ItemExit.bmp");
}

void ItemExit::onClick()
{
	Application::quit();
}
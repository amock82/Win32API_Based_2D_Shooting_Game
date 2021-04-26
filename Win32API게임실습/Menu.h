#pragma once

#include "Sprite.h"
#include "Button.h"

//////////////////////////
//		메뉴 클래스		//
//////////////////////////
class Menu : public Sprite
{
private:

public:
	Menu(float px, float py);
	virtual ~Menu();

	virtual void start();
};

//////////////////////////////////
//		이어하기 버튼 클래스		//
//////////////////////////////////
class ItemResume : public Button
{
private:

public:
	ItemResume(float px, float py);
	virtual ~ItemResume();

	virtual void start();
	virtual void onClick();
};

//////////////////////////////////
//		다시하기 버튼 클래스		//
//////////////////////////////////
class ItemRestart : public Button
{
private:

public:
	ItemRestart(float px, float py);
	virtual ~ItemRestart();

	virtual void start();
	virtual void onClick();
};

//////////////////////////////////
//		메인으로 버튼 클래스		//
//////////////////////////////////
class ItemMain : public Button
{
private:

public:
	ItemMain(float px, float py);
	virtual ~ItemMain();

	virtual void start();
	virtual void onClick();
};

//////////////////////////////////
//		게임종료 버튼 클래스		//
//////////////////////////////////
class ItemExit : public Button
{
private:

public:
	ItemExit(float px, float py);
	virtual ~ItemExit();

	virtual void start();
	virtual void onClick();
};
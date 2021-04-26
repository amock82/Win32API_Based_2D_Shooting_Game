#pragma once

#include "Button.h"

//////////////////////////////
//		시작 버튼 클래스		//
//////////////////////////////
class BtnStart : public Button
{
private:

public:
	BtnStart(float px, float py);
	virtual ~BtnStart();

	virtual void start();
	virtual void onClick();
};


//////////////////////////////
//		모드 버튼 클래스		//
//////////////////////////////
class BtnMode : public Button
{
private:

public:
	BtnMode(float px, float py);
	virtual ~BtnMode();

	virtual void start();
	virtual void onClick();
};


//////////////////////////////
//		옵션 버튼 클래스		//
//////////////////////////////
class BtnOption : public Button
{
private:

public:
	BtnOption(float px, float py);
	virtual ~BtnOption();

	virtual void start();
	virtual void onClick();
};


//////////////////////////////
//		종료 버튼 클래스		//
//////////////////////////////
class BtnQuit : public Button
{
private:

public:
	BtnQuit(float px, float py);
	virtual ~BtnQuit();

	virtual void start();
	virtual void onClick();
};
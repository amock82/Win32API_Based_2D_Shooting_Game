#include "framework.h"

HPBar::HPBar(float px, float py) : GameObject("UI", "체력바", true, px, py)
{
	this->fillAmount = 1;
}

HPBar::~HPBar(){}

void HPBar::start()
{
	//배경, 막대 이미지 로드
	readBMP("Asset/UI/HP_BG.bmp", &bg);
	readBMP("Asset/UI/HP.bmp", &bar);

	addChildObj(new Text(L"HP:100", 10, 18), 5);
}

void HPBar::draw()
{
	float x = getPx();
	float y = getPy();

	drawBMP(x + 2, y + 3, &bar, fillAmount);
	drawBMP(x, y, &bg);
}

void HPBar::setFillAmount(float fillAmount)
{
	this->fillAmount = fillAmount;
}

void HPBar::setValue(int value)
{
	Text* text = (Text*)getChild(0);

	//정수를 문자열로 변환하기 (wsprintf)
	//WCHAR buffer[30];
	//wsprintf(buffer, L"%d", value);

	//text->setText(buffer);

	text->setText(L"HP:" + to_wstring(value));
}
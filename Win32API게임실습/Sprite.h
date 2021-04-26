#pragma once

#include "GameObject.h"
#include "BMP.h"

class Sprite : public GameObject
{
private:
	//스프라이트 이미지 구조체//
	Image image;
public:
	Sprite(string tag, string name, bool active, float px, float py);
	virtual ~Sprite();

	//이미지 구조체 로드함수//
	void setImage(string  fileName);
	void setImage(string  fileName,int x, int y, int width, int height);
	void setImage(Image  &image);
	void resetImage();

	//가상함수 오버라이딩//
	virtual void draw();

	//이미지 구조체 정보 게터
	int getImageWidth();
	int getImageHeight();
	void getImageRect(int& width, int& height);
};

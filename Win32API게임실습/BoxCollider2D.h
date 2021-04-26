#pragma once

class BoxCollider2D
{
private:
	float x, y;          //사각형 충돌체 왼쪽 상단 꼭지점
	float width, height; //사각형 가로/세로 길이

public:
	BoxCollider2D();
	BoxCollider2D(float x, float y, float width, float height);
	
	virtual ~BoxCollider2D();

	void getBoundingBox(float& x, float& y, float& width, float& height);
	void translate(float tx, float ty);
};
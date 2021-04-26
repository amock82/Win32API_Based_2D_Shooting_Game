#pragma once

#include <vector>
#include "GameObject.h"

using namespace std;

#define MAX_LAYER 8

class ObjectManager
{
private:	
	static vector<GameObject*> gameObject[MAX_LAYER];
	static bool isShowGizmo;

public:
	//게임오브젝트 추가, 삭제 하기//
	static GameObject* instantiate(GameObject* obj, int layer = 0);
	static void destroy(GameObject* obj);

	//게임오브젝트 업데이트
	static void update();

	//게임오브젝트 충돌검사
	static void checkCollision();

	//삭제대상 객체들..모두 삭제하기
	static void clearDeadObj();

	//게임오브젝트 그리기
	static void draw();

	//게임오브젝들 모두 삭제하기
	static void exit();

	//객체 찾아오기
	static GameObject* find(string name);
};

#pragma once

#include <vector>
#include <string>

#include "GameObject.h"

using namespace std;

class ObjectPool
{
private:
	static vector<GameObject*> pool;

public:

	// ObjectPool 초기화
	static void init();

	// 풀에 객체 추가하기
	static void push(GameObject* o);
	
	// 풀에서 객체 가져오기
	static GameObject* pop(string tag, string name);
};
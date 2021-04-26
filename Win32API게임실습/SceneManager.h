#pragma once

#include "Scene.h"

class SceneManager
{
private:
	static Scene* scene;

public:
	static void init();
	static void run();

	//씬전환 함수
	static void loadScene(Scene*);	//함수 정보(원형)에서 매개변수 이름은 사용안됨
									//즉, 왼쪽에서 씬 객체의 주소 1개가 매개변수로 전달된다
};
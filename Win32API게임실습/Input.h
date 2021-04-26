#pragma once

#include <string>

using namespace std;

#define MAX_KEY 10

struct MousePosition
{
	int x;
	int y;
};

class Input
{
private:

	enum State { keyUpRep = 0, keyDown = 1, keyDownRep = 2, keyUp = 3 };

	static int key[MAX_KEY];
	static int state[MAX_KEY];
	static string name[MAX_KEY];

public:

	//마우스 좌표 저장 변수
	static MousePosition mousePosition;

	static void init();
	static void update();

	//키검사 함수//
	static bool getKey(string keyCode);
	static bool getKeyDown(string keyCode);
	static bool getKeyUp(string keyCode);

	//마우스 버튼 검사 함수//
	static bool getMouseButton(int button); //	0 = L | 1 = R | 2 = M
	static bool getMouseButtonDown(int button);
	static bool getMouseButtonUp(int button);
};


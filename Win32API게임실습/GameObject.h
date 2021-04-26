#pragma once

#include <string>
#include <vector>

#include "BoxCollider2D.h"

using namespace std;

class GameObject
{
private:
	//기본 속성//
	string tag;
	string name;
	bool active;
	bool alive;  //객체가 살아있는지를 표시하는 변수 

	//Transform 속성//
	float px, py;

	//게임오브젝트 충돌체//
	vector<BoxCollider2D> collider;

	//자식 게임 오브젝트//
	vector<GameObject*> childObj;

public:
	//부모 게임 오브젝트//
	GameObject* parent;

	///생성자, 소멸자///
	GameObject(string tag, string name, bool active, float px, float py);
	virtual ~GameObject();

	//게터, 세터//
	string getTag();
	string getName();
	bool   getActive();

	float getPx();
	float getPy();
	void  getPosition(float& px, float& py);
	bool  getAlive();

	vector<BoxCollider2D> getCollider();

	void setTag(string tag);
	void setName(string name);
	void setActive(bool active);

	void setPx(float px);
	void setPy(float py);
	void setPosition(float px, float py);

	void setAlive(bool alive);

	//기본 가상함수//
	virtual void start();
	virtual void update();
	virtual void draw();

	//이동함수//
	void translate(float x, float y);

	//충돌체 추가함수
	void addBoxCollider2D(float x, float y, float width, float height);
	void addBoxCollider2D(BoxCollider2D collider);

	//자식객체 추가, 제거하기
	void addChildObj(GameObject* obj, int layer = 0);
	void delChildObj(GameObject* obj);

	//자식객체 찾아오기
	GameObject* getChild(int index);
	GameObject* find(string name);

	//자식객체 갯수 구하기
	int getChildCount();

	//충돌체 기즈모 그리기함수//
	virtual void onDrawGizmos();

	//충돌 이벤트 처리함수 //
	virtual void onTriggerStay(GameObject * other);
};
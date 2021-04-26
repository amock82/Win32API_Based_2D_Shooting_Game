#include "framework.h"

///생성자, 소멸자///
GameObject::GameObject(string tag, string name, bool active, float px, float py)
{
	this->tag    = tag;
	this->name   = name;
	this->active = active;
	this->alive  = true;

	this->px = px;
	this->py = py;
		
	this->parent = nullptr;
}

GameObject::~GameObject()
{
}

//게터, 세터//
string GameObject::getTag()
{
	return tag;
}

string GameObject::getName()
{
	return name;
}

bool GameObject::getActive()
{
	return active;
}

float GameObject::getPx()
{
	return px;
}

float GameObject::getPy()
{
	return py;
}

void GameObject::getPosition(float& px, float& py)
{
	px = this->px;
	py = this->py;
}

vector<BoxCollider2D> GameObject::getCollider()
{
	return collider;
}

bool GameObject::getAlive()
{
	return alive;
}

void GameObject::setTag(string tag)
{
	this->tag = tag;
}

void GameObject::setName(string name)
{
	this->name = name;
}

void GameObject::setActive(bool active)
{
	this->active = active;

	//자식 객체들도 상태를 적용하기
	for (int i = 0; i < childObj.size(); i++)
	{
		childObj[i]->setActive(active);
	}
}

void GameObject::setPx(float px)
{
	float tx = px - this->px;

	//충돌체 이동시키기//
	for (int i = 0; i < collider.size(); i++)
	{
		collider[i].translate(tx, 0);
	}

	for (int i = 0; i < childObj.size(); i++)
	{
		childObj[i]->translate(tx, 0);
	}

    //게임객체 위치 변경
	this->px = px;
}

void GameObject::setPy(float py)
{
	float ty = py - this->py;

	//충돌체 이동시키기//
	for (int i = 0; i < collider.size(); i++)
	{
		collider[i].translate(0, ty);
	}

	for (int i = 0; i < childObj.size(); i++)
	{
		childObj[i]->translate(0, ty);
	}

	//게임객체 위치 변경
	this->py = py;
}

void GameObject::setPosition(float px, float py)
{
	setPx(px);
	setPy(py);
}

void GameObject::setAlive(bool alive)
{
	this->alive = alive;

	//자식객체들도 동일하게 alive 상태 적용하기
	for (int i = 0; i < childObj.size(); i++)
	{
		childObj[i]->setAlive(alive);
	}
}

void GameObject::translate(float x, float y)
{
	//게임객체 translate//
	this->px += x;
	this->py += y;

	//충돌체 translate//
	for (int i = 0; i < collider.size(); i++)
	{
		this->collider[i].translate(x, y);
	}

	// 자식객체 translate //
	for (int i = 0; i < childObj.size(); i++)
	{
		this->childObj[i]->translate(x, y);
	}
}

void GameObject::addBoxCollider2D(float x, float y, float width, float height)
{
	this->collider.push_back(BoxCollider2D(x + px, y + py, width, height));
}

void GameObject::addBoxCollider2D(BoxCollider2D collider)
{
	//게임객체를 기준으로..상대좌표로..변경함//
	collider.translate(px, py);
	this->collider.push_back( collider );
}

void GameObject::addChildObj(GameObject* obj, int layer)
{
	//자식객체에 부모객체 포인터 지정//
	obj->parent = this;

	//게임객체를 기준으로..상대좌표로..변경함//
	obj->translate(px, py);

	// 자식객체 목록체 추가하기
	this->childObj.push_back(obj);

	// 자식객체를 오브젝트매니저에 추가하기
	ObjectManager::instantiate(obj, layer);
}

void GameObject::delChildObj(GameObject* obj)
{
	//게임객체 목록에서 제거
	ObjectManager::destroy(obj);

	//자식객체 목록에서 제거
	for (int i = 0; i < childObj.size(); i++)
	{
		if (childObj[i] == obj)
		{
			childObj.erase(childObj.begin() + i);
			break;
		}
	}
}

GameObject* GameObject::getChild(int index)
{
	if (index < childObj.size())
	{
		return childObj[index];
	}
	
	return nullptr;
}

GameObject* GameObject::find(string name)
{
	for (int i = 0; i < childObj.size(); i++)
	{
		if (childObj[i]->getName() == name)
			return childObj[i];
	}

	return nullptr;
}

int GameObject::getChildCount()
{
	return childObj.size();
}

void GameObject::onDrawGizmos()
{
	if (active == true)
	{
		//충돌체 기즈모 그리기//
		float x, y, width, height;

		for (int i = 0; i < collider.size(); i++)
		{
			collider[i].getBoundingBox(x, y, width, height);

			//사각형 꼭지점
			float x0 = x;
			float y0 = y;
			float x1 = x + width;
			float y1 = y + height;

			drawRect(x0, y0, x1, y1, 0, 255, 0);
		}
	}
}

void GameObject::onTriggerStay(GameObject * other)
{}

void GameObject::start()
{}

void GameObject::update()
{}

void GameObject::draw()
{}
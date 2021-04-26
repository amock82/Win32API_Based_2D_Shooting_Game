#include "framework.h"

GuidLaser::GuidLaser(float px, float py, float angle) : Sprite("적기", "유도레이저", true, px, py)
{
	this->speed = 200;
	this->radian = angle * M_PI / 180;

	this->lifeTime = 3.5;
}

GuidLaser::~GuidLaser(){}

void GuidLaser::start()
{
	setImage("Asset/적기총알2.bmp");

	addBoxCollider2D(0, 0, 17, 17);
}

void GuidLaser::update()
{
	lifeTime -= Timer::deltaTime;

	//현재 위치에서 타겟 벡터 구하기
	GameObject* target = ObjectManager::find("팬텀");
	float tx, ty;

	if (target != nullptr)
	{
		tx = target->getPx() + 31 - this->getPx();
		ty = target->getPy() + 40 - this->getPy();
	}
	else
	{
		tx = WIDTH / 2 - this->getPx();
		ty = HEIGHT * 1.2 - this->getPy();
	}

	//레이저 방향(단위)벡터 구하기
	float nx = cos(radian);
	float ny = sin(radian);

	//(tx, ty)와 (nx, ny) 벡터간의 사잇각 구하기
	float dot = tx * nx + ty * ny;
	float lnxy = 1; //sqrt(nx * nx + ny * ny);	// 항상1
	float ltxy = sqrt(tx * tx + ty * ty);

	float theta = acos(dot / (lnxy * ltxy));	//두 벡터의 사잇각

	//외적으로 타겟방향 구하기
	float cross = nx * ty - ny * tx;

	if (cross < 0)
	{
		theta *= -1;
	}

	//새로운 진행 방향 구하기
	radian = radian + theta * 0.02;

	//레이저를 radian 방향으로 이동시키기
	float dx = cos(radian) * speed * Timer::deltaTime;
	float dy = sin(radian) * speed * Timer::deltaTime;

	translate(dx, dy);

	//printf("%f  %f\n", this->getPx(), this->getPy());

	if (lifeTime <= 0)
	{
		explode();
	}
}

void GuidLaser::onTriggerStay(GameObject* other)
{
	string tag = other->getTag();
	string name = other->getName();

	if (tag == "플레이어")
	{
		if (name == "팬텀" || name == "방패")
		{
			explode();
		}
	}
}

void GuidLaser::explode()
{
	//풀에서 폭발효과 가져와서 자폭효과
	float x = getPx();
	float y = getPy();

	GameObject* exp = ObjectPool::pop("폭발효과", "레이저폭발");

	if (exp != nullptr)
	{
		//풀에서 가져온 객체 속성을 재설정
		exp->setPosition(x - 8, y);
		exp->setActive(true);
	}
	else {
		cout << "레이저 폭발 객체가 풀에 없음" << endl;
	}

	//레이저 객체 제거
	ObjectManager::destroy(this);
}
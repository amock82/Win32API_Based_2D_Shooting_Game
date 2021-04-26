#include "framework.h"

// 유니티에서는 stl vector는  ArrayList 또는 List를 활용함
vector<GameObject*> ObjectPool::pool;

void ObjectPool::init()
{
	pool.clear();
}

void ObjectPool::push(GameObject* o)
{
	pool.push_back(o);
}

GameObject* ObjectPool::pop(string tag, string name)
{

	for (int i = 0; i < pool.size(); i++)
	{
		string poolTag    = pool[i]->getTag();
		string poolName   = pool[i]->getName();
		bool   poolActive = pool[i]->getActive();

		if (poolActive == false && poolTag == tag && poolName == name)
		{
			return pool[i];
		}
	}

	return pool[0];
}
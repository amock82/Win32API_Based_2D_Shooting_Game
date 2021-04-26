#include "framework.h"

vector<GameObject*> ObjectManager::gameObject[MAX_LAYER];
bool ObjectManager::isShowGizmo = true;

GameObject* ObjectManager::instantiate(GameObject* obj, int layer)
{
	gameObject[layer].push_back(obj);
	obj->start();

	return obj;
}

void ObjectManager::destroy(GameObject* obj)
{
	obj->setAlive(false);

	/** 또는 
	for (int i = 0; i < gameObject.size(); i++)
	{
		if (gameObject[i] == obj)
		{
			obj->setAlive(false);
			break; //삭제 후... 반복문 종료
		}
	}
	**/
}

void ObjectManager::update()
{
	for (int layer = 0; layer < MAX_LAYER; layer++)
	{
		for (int i = 0; i < gameObject[layer].size(); i++)
		{
			GameObject* o = gameObject[layer].at(i);
			o->update();
		}
	}
}

void ObjectManager::checkCollision()
{
	// 충돌검사를 위해서 모든 레이어의 객체를 1차원 배열로 만듦
	vector<GameObject*> tempObject;
	
	for (int layer = 0; layer < MAX_LAYER; layer++)
	{
		for (int i = 0; i < gameObject[layer].size(); i++)
		{
			tempObject.push_back(gameObject[layer][i]);
		}
	}

	for (int j = 0; j < tempObject.size(); j++)
	{
		for (int i = 0; i < tempObject.size(); i++)
		{
			if (i > j)
			{
				GameObject* objJ = tempObject[j];  //테스트에서 플레이어 객체
				GameObject* objI = tempObject[i];  //테스트에서 아야코 객체

				if (objJ->getActive() == true && objI->getActive() == true)
				{
					//충돌검사 객체쌍에서 충돌체 가져오기//
					vector<BoxCollider2D> colJ = objJ->getCollider();
					vector<BoxCollider2D> colI = objI->getCollider();

					for (int jj = 0; jj < colJ.size(); jj++)
					{
						for (int ii = 0; ii < colI.size(); ii++)
						{
							//충돌체 사각형 바운딩 박스..좌표 가져오기
							float x, y, width, height;
							float x0j, y0j, x1j, y1j;  //colJ의 사각형 좌표
							float x0i, y0i, x1i, y1i;  //colI의 사각형 좌표

							colJ[jj].getBoundingBox(x, y, width, height);

							x0j = x;
							y0j = y;
							x1j = x + width;
							y1j = y + height;

							colI[ii].getBoundingBox(x, y, width, height);

							x0i = x;
							y0i = y;
							x1i = x + width;
							y1i = y + height;

							if (y1i > y0j && y1j > y0i && x1j > x0i && x1i > x0j)
							{
								objJ->onTriggerStay(objI);  //충돌이벤트 발생시킴
								objI->onTriggerStay(objJ);  //충돌이벤트 발생시킴
							}
						}
					}
				}
			}
		}
	}
	
	// tempObject 클리어
	tempObject.clear();
}

void ObjectManager::clearDeadObj()
{
	for (int layer = 0; layer < MAX_LAYER; layer++)
	{
		for (int i = 0; i < gameObject[layer].size(); i++)
		{
			if (gameObject[layer][i]->getAlive() == false)
			{
				GameObject* obj = gameObject[layer][i];

				gameObject[layer].erase(gameObject[layer].begin() + i);
				delete obj;

				i--;
			}
		}
	}
}

void ObjectManager::draw()
{
	//기즈모 출력 키 토글(toggle) 입력 받기//
	if (Input::getKeyDown("F1") == true)
	{
		if (isShowGizmo == true)
		{
			isShowGizmo = false;
		}
		else {
			isShowGizmo = true;
		}
	}

	for (int layer = 0; layer < MAX_LAYER; layer++)
	{
		for (int i = 0; i < gameObject[layer].size(); i++)
		{
			//게임 이미지(스플라이트) 그리기
			GameObject* o = gameObject[layer][i];
			
			if (o->getActive() == true)
			{
				o->draw();

				if (isShowGizmo == true)
				{
					//게임 기즈모(충돌체) 그리기
					o->onDrawGizmos();
				}
			}
		}
	}
}

void ObjectManager::exit()
{
	for (int layer = 0; layer < MAX_LAYER; layer++)
	{
		for (int i = 0; i < gameObject[layer].size(); i++)
		{
			GameObject* o = gameObject[layer].at(i);
			delete o;
		}

		gameObject[layer].clear();
	}
}

GameObject* ObjectManager::find(string name)
{
	for (int layer = 0; layer < MAX_LAYER; layer++)
	{
		for (int i = 0; i < gameObject[layer].size(); i++)
		{
			if (gameObject[layer][i]->getName() == name)
				return gameObject[layer][i];
		}
	}

	return nullptr;
}
#include "framework.h"

GameScene::GameScene(){}

GameScene::~GameScene(){}

void GameScene::load()
{
    GameManager::init();
    ObjectPool::init();

    //게임객체 로드하기//
    ObjectManager::instantiate(new GameBG(0, 0));

    // EnemyManager 추가 //
    ObjectManager::instantiate(new EnemyManager(WIDTH / 2, 0), 0);

    // 비행기,레이저 폭발 [오브젝트 풀] 테스트 //
    for (int i = 0; i < 10; i++)
    {
        GameObject* obj = ObjectManager::instantiate(new ShipExp(0, 0), 3);

        obj->setActive(false);
        ObjectPool::push(obj);
    }

    for (int i = 0; i < 200; i++)
    {
        GameObject* obj = ObjectManager::instantiate(new LaserExp(0, 0), 3);

        obj->setActive(false);
        ObjectPool::push(obj);
    }

    GameManager::restartPlayer();
}

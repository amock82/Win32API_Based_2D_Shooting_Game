#include "framework.h"

Scene::Scene(){}

Scene::~Scene()
{
    //ObjectManager의 모든 객체 제거하기
    ObjectManager::exit();
}

void Scene::load()
{
    
}

void Scene::run()
{
    ObjectManager::update();
    ObjectManager::checkCollision();
    ObjectManager::clearDeadObj();
    ObjectManager::draw();
}
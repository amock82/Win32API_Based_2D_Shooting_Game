#include "framework.h"

EndingScene::EndingScene() : Scene()
{

}

EndingScene::~EndingScene(){}

void EndingScene::load()
{
	ObjectManager::instantiate(new EndingBG(80, 400 - 475/2), 0);
}
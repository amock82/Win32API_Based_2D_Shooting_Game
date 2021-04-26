#include "framework.h"

TitleScene::TitleScene(){}
TitleScene::~TitleScene(){}

void TitleScene::load()
{
    ObjectManager::instantiate(new TitleBG(0, 0), 0);

    ObjectManager::instantiate(new BtnStart(250, 500), 5);
    ObjectManager::instantiate(new BtnMode(250, 560), 5);
    ObjectManager::instantiate(new BtnOption(250, 620), 5);
    ObjectManager::instantiate(new BtnQuit(250, 680), 5);
}

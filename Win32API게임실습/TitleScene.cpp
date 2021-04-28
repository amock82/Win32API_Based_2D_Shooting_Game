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
    
    // 게임 타이틀 출력하기
    ObjectManager::instantiate(new Text(L"2D 슈팅게임 실습", 58, 255, 255, 255, 10, 100), 5);

    // 게임 완성 날짜, 버전
    ObjectManager::instantiate(new Text(L"Date : 2021-04-28", 280, 760), 5);
    ObjectManager::instantiate(new Text(L"Version : 1.0.0", 280, 780), 5);

    // 폰트 테스트하기
    //ObjectManager::instantiate(new Text(L"ABC", 32, 200, 200, 0, 100, 100), 5);
    //ObjectManager::instantiate(new Text(L"테스트", 64, 0, 200, 200, 100, 64), 5);
}

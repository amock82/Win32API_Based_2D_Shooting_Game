#include "framework.h"

Scene* SceneManager::scene = nullptr;

void SceneManager::init()
{
	scene = new TitleScene();
	scene->load();
}

void SceneManager::run()
{
	scene->run();
}

void SceneManager::loadScene(Scene* nextScene)
{
	delete scene;	//ÀÌÀü ¾À »èÁ¦ÇÏ±â

	//´ÙÀ½ ¾À
	scene = nextScene;
	scene->load();
}
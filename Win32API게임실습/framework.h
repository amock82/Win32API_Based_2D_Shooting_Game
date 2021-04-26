// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <iostream>
#include <time.h>
#define _USE_MATH_DEFINES
#include <math.h>

#include "debug.h"
#include "Timer.h"
#include "graphic.h"
#include "BMP.h"
#include "GameObject.h"
#include "Sprite.h"
#include "ObjectManager.h"
#include "GameBG.h"
#include "Player.h"
#include "PlayerLaser.h"
#include "Animation.h"
#include "Ayako.h"
#include "BoxCollider2D.h"
#include "LaserExp.h"
#include "PlayerBomb.h"
#include "Input.h"
#include "BombExp.h"
#include "ShipExp.h"
#include "ObjectPool.h"
#include "EnemyLaser.h"
#include "EnemyManager.h"
#include "Random.h"
#include "GameManager.h"
#include "Shield.h"
#include "Stealth.h"
#include "GuidLaser.h"
#include "Shooter.h"
#include "Boss.h"
#include "Propeller.h"
#include "Wing.h"
#include "BossGun.h"
#include "WingGun.h"
#include "Radar.h"
#include "BossChildExp.h"
#include "DeadBoss.h"
#include "ReturnPlayer.h"
#include "LaserItem.h"
#include "BombItem.h"
#include "GameOver.h"
#include "PlayerIcon.h"
#include "HPBar.h"
#include "BombIcon.h"
#include "Button.h"
#include "BTNExit.h"
#include "BTNPause.h"
#include "Application.h"
#include "Menu.h"
#include "Scene.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "TitleBG.h"
#include "SceneManager.h"
#include "TitleMenu.h"
#include "EndingScene.h"
#include "EndingBG.h"

#define WIDTH  480  //게임화면 가로길이
#define HEIGHT 800  //게임화면 세로길이

using namespace std;
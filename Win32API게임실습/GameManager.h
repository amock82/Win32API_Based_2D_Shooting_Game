#pragma once

class GameManager
{
private:
	//아야코 카운터 변수
	static int ayakoSpawnCount;
	static int ayakoDelCount;

	//스텔스 카운터 변수
	static int stealthSpawnCount;
	static int stealthDelCount;

	//플레이어 카운트
	static int playerCount;

	//플레이어 체력
	static float playerHP;

	//스테이지 클리어변수//
	static bool stageClear;

	//플레이어 아이콘 UI 객체 포인터 배열
	static GameObject* playerIcon[3];

	//플레이어 객체 포인터
	static GameObject* playerObj;

	//플레이어 체력바 UI 객체 포인터
	static GameObject* playerHPBar;

	//폭탄 아이콘 UI 객체 포인터 배열
	static GameObject* bombIcon[5];

	//폭탄갯수 변수
	static int bombCount;

public:
	//게임매니저 초기화 함수
	static void init();

	//아야코 카운터 함수
	static void addAyakoCount();
	static void delAyakoCount();
	static int getAyakoCount();

	//스텔스 카운터 함수
	static void addStealthCount();
	static void delStealthCount();
	static int getStealthCount();

	//스테이지 클리어 세터, 게터//
	static void setStageClear(bool clear);
	static bool getStageClear();

	//플레이어 리스폰 함수
	static void restartPlayer();

	//플레이어 피해 함수
	static void damagePlayer(float damage);

	//플레이어 체력 출력
	static void showHPBar();

	//플레이어 폭탄 카운트 함수
	static int getBombCount();
	static void addBombCount();
	static void subBombCount();

	//폭탄아이콘 보이기함수
	static void showBombIcon();

	//게임 일시정지 변수
	static bool isPause;
};
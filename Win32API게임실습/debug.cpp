#include "framework.h"

#pragma warning(disable:4996)

void START_DEBUG_CONSOLE()
{
    AllocConsole();                  //윈도우에서 콘솔창 시작하기 함수

    freopen("CONOUT$", "w", stdout); //printf 또는 cout 에 의해서 출력되는 표준 출력창으로 만듬
    freopen("CONIN$", "r", stdin);   //scanf_s 또는 cin 에 의해서 입력을 받을 수 있는 표준 입력 창으로 만듬
}

void STOP_DEBUG_CONSOLE()
{
    FreeConsole();                   //윈도우에서 콘솔창 종료하기 함수
}
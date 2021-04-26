#pragma once

#include <Windows.h>

void initGraphic(HWND hWnd, int x, int y, int width, int height);  //그래픽 출력 초기화
void exitGraphic();                                                //그래픽 출력 종료 

void clear(unsigned char r, unsigned char g, unsigned char b);     //r, g, b 색으로..백버퍼를 초기화함

void render(); //백버퍼의...그래픽 데이타를 화면(윈도우 영역)에 출력

void setPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b); //x,y 위치에 r, g, b 색상출력
void setPixel(int x, int y, unsigned int color); //x, y 위치에 r, g, b 색상출력(알파값 적용)

void getPixel(int x, int y, unsigned char &r, unsigned char &g, unsigned char &b);  //x,y 위치에서..이미 출력된 r, g, b값을 가져옴
void getPixel(int x, int y, unsigned char *r, unsigned char *g, unsigned char *b);  //x,y 위치에서..이미 출력된 r, g, b값을 가져옴

void drawLine(int x0, int y0, int x1, int y1, unsigned char r, unsigned char g, unsigned char b); //(x0, y0)에서 (x1, y1)을 잇는 직선그리기 - r, g, b 색 직선
void drawCircle(int cx, int cy, int radius, unsigned char r, unsigned char g, unsigned b);        //중심이(cx, cy)이고 반지름이 radius인 원 그리기 - r, g, b 색 직선
void drawRect(int x0, int y0, int x1, int y1, unsigned char r, unsigned char g, unsigned char b); //왼쪽상단꼭지점 (x0, y0)과 오른쪽꼭지점 (x1, y1)으로  사각형 그리기 - r, g, b 색 직선

int getClientWidth();      //그래픽 출력 사각형의 가로 길이를 반환함
int getClientHeight();     //그래픽 출력 사각형의 세로 길이를 반환함

HWND GetConsoleHwnd();
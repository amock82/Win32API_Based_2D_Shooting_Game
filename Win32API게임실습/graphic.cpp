#include <Windows.h>
#include <math.h>
#include "graphic.h"

#ifndef SafeDeleteArray
    #define SafeDeleteArray(_X_) if ( (_X_) != NULL) { delete[] (_X_);  (_X_) = NULL;}
#endif

static HWND outHWnd     = NULL;  //그래픽 출력 윈도우 핸들

static int  clientX      = 0;   //그래픽 출력 영역(사각형 영역)의 시작 x-좌표
static int  clientY      = 0;   //그래픽 출력 영역(사각형 영역)의 시작 y-좌표
static int  clientWidth  = 0;   //그래픽 출력 영역(사각형 영역)의 가로 길이(너비)
static int  clientHeight = 0;   //그래픽 출력 영역(사각형 영역)의 세로 길이(높이)

static unsigned int * backBuffer = NULL; //그래픽 출력 백버퍼

/////////////////////그래픽 출력 초기화 함수//////////////////////
void initGraphic(HWND hWnd, int x, int y, int width, int height)
{
    if (hWnd == NULL)  //그래픽 출력..핸들이 NULL 이면 콘솔윈도우의..핸들을 구해서 사용한다.
    {
        outHWnd = GetConsoleHwnd();
    }
    else {
        outHWnd = hWnd;
    }

    /////////////그래픽 출력 영역(사각형 영역)의 위치와 크기를 정적(static)변수에 저정한다///////////////
    clientX = x;
    clientY = y;
    clientWidth  = width;
    clientHeight = height;

    ////////////백버퍼를 동적 생성한다.//////////////
    backBuffer = new unsigned int[clientWidth * clientHeight];
}

int getClientWidth()      //그래픽 출력 사각형의 가로 길이를 반환함
{
    return clientWidth;
}

int getClientHeight()     //그래픽 출력 사각형의 세로 길이를 반환함
{
    return clientHeight;
}

///////////////////r, g, b 색으로 백버퍼를 초기화 하는 함수////////////////////////////////////////////
void clear(unsigned char r, unsigned char g, unsigned char b)     //r, g, b 색으로..백버퍼를 초기화함
{
    unsigned int color = (r << 16) | (g << 8) | (b << 0);

    for (int j = 0; j < clientHeight; j++)
    {
        for (int i = 0; i < clientWidth; i++)
        {
            backBuffer[j*clientWidth + i] = color;
        }
    }
}

/////////////////r, g, b 값을 x, y 위치에 출력하는 함수/////////////////////
void setPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b) //x,y 위치에 r, g, b 색상출력
{
    if (0 <= x && x < clientWidth && 0 <= y && y < clientHeight)
    {
        unsigned int color = (r << 16) | (g << 8) | (b << 0);
        backBuffer[y*clientWidth + x] = color;
    }
}

/////////////////color(a, r, g, b)를 x, y 위치에 출력하는 함수////////////////////
void setPixel(int x, int y, unsigned int color) //x, y 위치에 r, g, b 색상출력(알파값 적용)
{
    if (0 <= x && x < clientWidth && 0 <= y && y < clientHeight)
    {
        ///////////////출력색상의 a, r, g, b/////////////
        unsigned char a = (color >> 24) & 0xff;
        unsigned char r = (color >> 16) & 0xff;
        unsigned char g = (color >>  8) & 0xff;
        unsigned char b = (color >>  0) & 0xff;

        /////////////배경색상(백버퍼에 출력된)의 r, g, b//////
        unsigned char R, G, B;
        getPixel(x, y, &R, &G, &B);

        //알파블렌딩 공식에 의해서 배경색과..이미지 픽셀을 섞는다.
        r = ((255 - a)*R + a * r) / 255;
        g = ((255 - a)*G + a * g) / 255;
        b = ((255 - a)*B + a * b) / 255;

        //알파블렌딩된..색상을 ..백버퍼에 출력한다
        setPixel(x, y, r, g, b);
    }
}

////////////////////////백버퍼에서 이미출력된 색상(r, g, b)를 가져온다////////////////////
void getPixel(int x, int y, unsigned char &r, unsigned char &g, unsigned char &b)  //x,y 위치에서..이미 출력된 r, g, b값을 가져옴
{
    if (0 <= x && x < clientWidth && 0 <= y && y < clientHeight)
    {
        unsigned int color = backBuffer[y*clientWidth + x];

        r = (color >> 16) & 0xff;
        g = (color >>  8) & 0xff;
        b = (color >>  0) & 0xff;
    }
    else {
        r = g = b = 0;
    }
}

void getPixel(int x, int y, unsigned char *r, unsigned char *g, unsigned char *b)  //x,y 위치에서..이미 출력된 r, g, b값을 가져옴
{
    getPixel(x, y, *r, *g, *b);
}

//////////////////////시작점이 (x0, y0)이고 끝점이 (x1, y1)인 직선을 r, g, b 색상으로 백버퍼에 출력한다/////////
void drawLine(int x0, int y0, int x1, int y1, unsigned char r, unsigned char g, unsigned char b) //(x0, y0)에서 (x1, y1)을 잇는 직선그리기 - r, g, b 색 직선
{
    //////////////////Bresenham Algorithms 으로 라인 그리기///////////////
    ////[라인 그리기 참조 사이트] https://gist.github.com/bert/1085538
    int dx = abs(x1 - x0), sx = x0<x1 ? 1 : -1;
    int dy = abs(y1 - y0), sy = y0<y1 ? 1 : -1;
    int err = (dx>dy ? dx : -dy) / 2, e2;

    for (;;) 
    {
        setPixel(x0, y0, r, g, b);

        if (x0 == x1 && y0 == y1) break;

        e2 = err;
        if (e2 >-dx) { err -= dy; x0 += sx; }
        if (e2 < dy) { err += dx; y0 += sy; }
    }
}
//////////////////////////////중심점 (cx, cy)이고 반지름이 radius 인 원을 r, g, b색상으로 백버퍼에 그린다///////////////
void drawCircle(int cx, int cy, int radius, unsigned char r, unsigned char g, unsigned b) //중심이(cx, cy)이고 반지름이 radius인 원 그리기 - r, g, b 색 직선
{
    /***********************************************************************
    int x = 0, y = 0;

    for (x = 0; x <= y; x++)
    {
        y = (int)(sqrt(radius*radius - x * x) + 0.5); // y 축 좌표를 계산한다.

        setPixel(cx + x, cy + y, r, g, b); 
        setPixel(cx + x, cy - y, r, g, b);
        setPixel(cx - x, cy + y, r, g, b);
        setPixel(cx - x, cy - y, r, g, b);
        setPixel(cx + y, cy + x, r, g, b);
        setPixel(cx + y, cy - x, r, g, b);
        setPixel(cx - y, cy + x, r, g, b);
        setPixel(cx - y, cy - x, r, g, b);
    }
    ***************************************************************************/
    ////[원그리기 참조 사이트] https://gist.github.com/bert/1085538
    int x = -radius, y = 0, err = 2 - 2 * radius; /* II. Quadrant */

    do {
        setPixel(cx - x, cy + y, r, g, b); /*   I. Quadrant */
        setPixel(cx - y, cy - x, r, g, b); /*  II. Quadrant */
        setPixel(cx + x, cy - y, r, g, b); /* III. Quadrant */
        setPixel(cx + y, cy + x, r, g, b); /*  IV. Quadrant */
        radius = err;
        if (radius >  x) err += ++x * 2 + 1; /* e_xy+e_x > 0 */
        if (radius <= y) err += ++y * 2 + 1; /* e_xy+e_y < 0 */

    } while (x < 0);
}

///////////////////// (x0, y0)이 왼쪽 상단 꼭지점이고, (x1, y1)오른쪽 하단 꼭지점인 사각형을 r, g, b색상으로 백버퍼에 그린다///////////
void drawRect(int x0, int y0, int x1, int y1, unsigned char r, unsigned char g, unsigned char b) //왼쪽상단꼭지점 (x0, y0)과 오른쪽꼭지점 (x1, y1)으로  사각형 그리기 - r, g, b 색 직선
{
    drawLine(x0, y0, x1, y0, r, g, b);
    drawLine(x0, y1, x1, y1, r, g, b);

    drawLine(x0, y0, x0, y1, r, g, b);
    drawLine(x1, y0, x1, y1, r, g, b);
}

///////////////////백버퍼의.. 그래픽 데이타(백버퍼에 출력된 픽셀)를 해당 윈도우..영역에 출력한다//////////////
void render() //백버퍼의...그래픽 데이타를 화면(윈도우 영역)에 출력
{
    HDC hDC, hMemDC;
    HBITMAP  hBmp;
    void   * bmpBuffer;
    int size;

    hDC    = GetDC(outHWnd);
    hMemDC = CreateCompatibleDC(hDC);
    size   = clientWidth * clientHeight * 4;

    BITMAPINFO bi;
    ZeroMemory(&bi, sizeof(BITMAPINFO));

    bi.bmiHeader.biSize     = sizeof(BITMAPINFOHEADER);
    bi.bmiHeader.biWidth    =  clientWidth;
    bi.bmiHeader.biHeight   = -clientHeight;
    bi.bmiHeader.biPlanes   = 1;
    bi.bmiHeader.biBitCount = 32;
    bi.bmiHeader.biCompression = BI_RGB;
   
    hBmp = CreateDIBSection(hDC, &bi, DIB_RGB_COLORS, &bmpBuffer, NULL, 0);
    SelectObject(hMemDC, hBmp);

    CopyMemory(bmpBuffer, backBuffer, size);

    BitBlt(hDC, clientX, clientY, clientWidth, clientHeight, hMemDC, 0, 0, SRCCOPY);

    DeleteObject(hBmp);
    DeleteDC(hMemDC);
    DeleteObject(hDC);
}

///////////////그래픽 출력 종료 함수////////////////////////////////
void exitGraphic()
{
    SafeDeleteArray(backBuffer);
}

#ifdef UNICODE

HWND GetConsoleHwnd()
{
    #define MY_BUFSIZE 1024 // Buffer size for console window titles.
	HWND hwndFound;         // This is what is returned to the caller.
	WCHAR pszNewWindowTitle[MY_BUFSIZE]; // Contains fabricated
										 // WindowTitle.
	WCHAR pszOldWindowTitle[MY_BUFSIZE];  // Contains original
										  // WindowTitle.

										  // Fetch current window title.

	GetConsoleTitle(pszOldWindowTitle, MY_BUFSIZE);
	// Format a "unique" NewWindowTitle.

	wsprintf(pszNewWindowTitle, L"%d/%d", GetTickCount(), GetCurrentProcessId());
	// Change current window title.

	SetConsoleTitle(pszNewWindowTitle);

	// Ensure window title has been updated.
	Sleep(40);

	// Look for NewWindowTitle.
	hwndFound = FindWindow(NULL, pszNewWindowTitle);

	// Restore original window title.
	SetConsoleTitle(pszOldWindowTitle);

	return(hwndFound);
}

#else

HWND GetConsoleHwnd()
{
    #define MY_BUFSIZE 1024 // Buffer size for console window titles.
	HWND hwndFound;         // This is what is returned to the caller.
	CHAR pszNewWindowTitle[MY_BUFSIZE]; // Contains fabricated
										 // WindowTitle.
	CHAR pszOldWindowTitle[MY_BUFSIZE];  // Contains original
										  // WindowTitle.

										  // Fetch current window title.

	GetConsoleTitle(pszOldWindowTitle, MY_BUFSIZE);
	// Format a "unique" NewWindowTitle.

	wsprintf(pszNewWindowTitle, "%d/%d", GetTickCount(), GetCurrentProcessId());
	// Change current window title.

	SetConsoleTitle(pszNewWindowTitle);

	// Ensure window title has been updated.
	Sleep(40);

	// Look for NewWindowTitle.
	hwndFound = FindWindow(NULL, pszNewWindowTitle);

	// Restore original window title.
	SetConsoleTitle(pszOldWindowTitle);

	return(hwndFound);
}

#endif

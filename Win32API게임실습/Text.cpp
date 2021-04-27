#include "framework.h"

// DLL 사용하기
#pragma comment (lib, "freetype.lib")

Text::Text(float px, float py) 
	: GameObject("UI", "텍스트", true, px, py)
{

}

Text::~Text()
{
    // 폰트사용 끝내기
    FT_Done_Face(face);
    FT_Done_FreeType(library);
}

void Text::start()
{
    // 폰트 라이브러리 초기화
    if (FT_Init_FreeType(&library) == 0)
    {
        cout << "폰트라이브러리 초기화 성공" << endl;
    }
    else
    {
        cout << "폰트라이브러리 초기화 실패" << endl;
    }

    // 폰트 파일 읽어오기
    if (FT_New_Face(library, "Asset/UI/DungGeunMo.ttf", 0, &face) == 0)
    {
        cout << "폰트파일 로드 성공" << endl;
    }
    else
    {
        cout << "폰트파일 로드 실패" << endl;
    }

    // 폰트 옵션 (크기 지정하기)
    FT_Set_Pixel_Sizes(face, 32, 32);
}

void Text::update()
{

}

void Text::draw()
{
    // 글자 모양 정보 위치 찾기
    WCHAR text[] = L"가나다___A,BC";

    // 폰트 출력 위치
    float fontx = getPx();
    float fonty = getPy();

    for (int i = 0; i < 10; i++)
    {
        int index = FT_Get_Char_Index(face, text[i]);          // text 글자 모양 정보 위치(인덱스) 구하기
        FT_Load_Glyph(face, index, 0);                      // index 위치에서 해당 글자 정보 로드하기. 로드 위치는 face->glyph
        FT_Render_Glyph(face->glyph, (FT_Render_Mode)0);    // face->glyph에 로드한 글자정보로 이미지정보 만들기 face->glyph->bitmap

        int width = face->glyph->bitmap.width; // 이미지 가로크기
        int height = face->glyph->bitmap.rows;  // 이미지 세로크기
        unsigned char* buffer = face->glyph->bitmap.buffer;

        //폰트 출력 사각형 내에서의 위치 재조정 변수
        int left = face->glyph->bitmap_left;
        int top  = face->glyph->bitmap_top;

        // 폰트 출력하기
        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                unsigned char v = buffer[y * width + x];

                if (v != 0)
                {
                    setPixel(fontx + x + left, fonty + y - top, 30, 30, 30);
                }
            }
        }

        // 폰트 출력 위치 증가시키기
        fontx += face->glyph->advance.x / 64;
        fonty -= face->glyph->advance.y / 64;
    }
}
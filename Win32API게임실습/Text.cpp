#include "framework.h"

// DLL 사용하기
#pragma comment (lib, "freetype.lib")

Text::Text(wstring text, int fontSize, unsigned char r, unsigned char g, unsigned char b, float px, float py)
	: GameObject("UI", "텍스트", true, px, py)
{
    this->text = text;
    this->fontSize = fontSize;

    this->r = r;
    this->g = g;
    this->b = b;
}

Text::Text(wstring text, float px, float py)
    : GameObject("UI", "텍스트", true, px, py)
{
    this->text = text;
    this->fontSize = 20;

    this->r = 255;
    this->g = 255;
    this->b = 255;
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
    //if (FT_New_Face(library, "Asset/UI/koverwatch.ttf", 0, &face) == 0)
    {
        cout << "폰트파일 로드 성공" << endl;
    }
    else
    {
        cout << "폰트파일 로드 실패" << endl;
    }

    // 폰트 옵션 (크기 지정하기)
    FT_Set_Pixel_Sizes(face, fontSize, fontSize);
}

void Text::update()
{

}

void Text::setText(wstring text)
{
    this->text = text;
}

void Text::draw()
{
    // 폰트 출력 위치
    float fontx = getPx();
    float fonty = getPy();

    for (int i = 0; i < text.size(); i++)
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
                
                float a = v / 255.0f;   // 알파 값
                
                // 배경색상
                unsigned char br, bg, bb;

                getPixel(fontx + x + left, fonty + y - top, br, bg, bb);

                // 알파블렌딩하기
                unsigned rr = r * a + br * (1 - a);
                unsigned rg = g * a + bg * (1 - a);
                unsigned rb = b * a + bb * (1 - a);

                
                if (v != 0)
                {
                    setPixel(fontx + x + left, fonty + y - top, rr, rg, rb);
                }
                
            }
        }

        // 폰트 출력 위치 증가시키기
        fontx += face->glyph->advance.x / 64;
        fonty -= face->glyph->advance.y / 64;
    }
}
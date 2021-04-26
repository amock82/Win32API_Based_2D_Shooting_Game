#pragma once

//이미지 구조체//
struct Image
{
	int width;
	int height;
	unsigned int* data;
};

bool readBMP(const char* fileName, Image* image);
bool readBMP(const char* fileName, int x, int y, int width, int height, Image* image);

void drawBMP(float px, float py, Image* image);
void drawBMP(float px, float py, Image* image, float fillAmount);
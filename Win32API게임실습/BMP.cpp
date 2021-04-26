#include "framework.h"

bool readBMP(const char* fileName, Image* image)
{
	FILE* stream;
	errno_t errno;

	//비트맵파일헤더 구조체 : BITMAPFILEHEADER
	BITMAPFILEHEADER fileHeader;
	//비트맵인터헤더 구조체 : BITMAPINFOHEADER
	BITMAPINFOHEADER infoHeader;
	//픽셀데이타 동적메모리 
	unsigned int* data = nullptr;

	errno = fopen_s(&stream, fileName, "rb");

	if (errno == 0 && stream != nullptr)
	{
		//printf("파일 열기 성공\n");
		//비트맵파일헤더..읽기
		fread(&fileHeader, sizeof(fileHeader), 1, stream);

		//비트맵파일헤더..출력
		//printf("----비트맵파일 헤더-----\n");
		//printf("bfType 0x%x\n", fileHeader.bfType);  //파일내부에서..파일종류는 구분하는 코드(매직코드)
		//printf("bfSize %d\n", fileHeader.bfSize);  //파일크기
		//printf("bfReserved1 %d\n", fileHeader.bfReserved1); //예약정보(현재 사용안됨)
		//printf("bfReserved2 %d\n", fileHeader.bfReserved2); //예약정보(현재 사용안됨)
		//printf("bfOffBits %d\n", fileHeader.bfOffBits);   //파일시작에서 비트맵데이타까지의 간격(Offset)

		//비트맵인포헤더..읽기
		fread(&infoHeader, sizeof(infoHeader), 1, stream);

		//비트맵인포헤더..출력
		//printf("----비트맵인포 헤더----\n");
		//printf("biWidth  %d\n", infoHeader.biWidth);      //이미지 가로크기
		//printf("biHeight %d\n", infoHeader.biHeight);     //이미지 세로크기
		//printf("biBitCount %d\n", infoHeader.biBitCount); //픽셀당 비트갯수
		//printf("biCompression %d\n", infoHeader.biCompression); //압축정보 (0은 압축되지 않음)
		//printf("biImageSize %d\n", infoHeader.biSizeImage);   //픽셀데이타..배열크기(바이트 갯수)
		//printf("biPlanes %d\n", infoHeader.biPlanes);  //이미지 갯수 (항상 1)

		//printf("biXPelsPerMeter %d\n", infoHeader.biXPelsPerMeter); //x축의 미터당 픽셀갯수
		//printf("biYPelsPerMeter %d\n", infoHeader.biYPelsPerMeter); //y축의 미터당 픽셀갯수

		//printf("biClrUsed %d\n", infoHeader.biClrUsed);           //이미지에서 사용된 color 갯수
		//printf("biClrImportant %d\n", infoHeader.biClrImportant); //이미지의 주요 color 갯수

		//이미지 형식 확인하기
		if (fileHeader.bfType == 0x4d42 && infoHeader.biBitCount == 32 && infoHeader.biClrImportant == 0)
		{
			//픽셀데이타 로드하기
			int length = infoHeader.biSizeImage / 4;

			data = new unsigned int[length];                    //로드공간 동적할당
			fread(data, sizeof(unsigned int), length, stream);  //픽셀데이타 로드하기

			//파일닫기
			fclose(stream);

			//이미지구조체에..필요정보 저장하기
			image->width = infoHeader.biWidth;
			image->height = infoHeader.biHeight;
			image->data = data;

			return true;
		}
		else {

			printf("잘못된 비트맵 파일 형식임\n");
			return false;
		}
	}
	else {
		printf("파일 열기 실패\n");
		return false;
	}

}

bool readBMP(const char* fileName, int x, int y, int width, int height, Image* image)
{
	FILE* stream;
	errno_t errno;

	//비트맵파일헤더 구조체 : BITMAPFILEHEADER
	BITMAPFILEHEADER fileHeader;
	//비트맵인터헤더 구조체 : BITMAPINFOHEADER
	BITMAPINFOHEADER infoHeader;
	//픽셀데이타 동적메모리 
	unsigned int* data = nullptr;

	errno = fopen_s(&stream, fileName, "rb");

	if (errno == 0 && stream != nullptr)
	{
		//printf("파일 열기 성공\n");
		//비트맵파일헤더..읽기
		fread(&fileHeader, sizeof(fileHeader), 1, stream);

		//비트맵파일헤더..출력
		//printf("----비트맵파일 헤더-----\n");
		//printf("bfType 0x%x\n", fileHeader.bfType);  //파일내부에서..파일종류는 구분하는 코드(매직코드)
		//printf("bfSize %d\n", fileHeader.bfSize);  //파일크기
		//printf("bfReserved1 %d\n", fileHeader.bfReserved1); //예약정보(현재 사용안됨)
		//printf("bfReserved2 %d\n", fileHeader.bfReserved2); //예약정보(현재 사용안됨)
		//printf("bfOffBits %d\n", fileHeader.bfOffBits);   //파일시작에서 비트맵데이타까지의 간격(Offset)

		//비트맵인포헤더..읽기
		fread(&infoHeader, sizeof(infoHeader), 1, stream);

		//비트맵인포헤더..출력
		//printf("----비트맵인포 헤더----\n");
		//printf("biWidth  %d\n", infoHeader.biWidth);      //이미지 가로크기
		//printf("biHeight %d\n", infoHeader.biHeight);     //이미지 세로크기
		//printf("biBitCount %d\n", infoHeader.biBitCount); //픽셀당 비트갯수
		//printf("biCompression %d\n", infoHeader.biCompression); //압축정보 (0은 압축되지 않음)
		//printf("biImageSize %d\n", infoHeader.biSizeImage);   //픽셀데이타..배열크기(바이트 갯수)
		//printf("biPlanes %d\n", infoHeader.biPlanes);  //이미지 갯수 (항상 1)

		//printf("biXPelsPerMeter %d\n", infoHeader.biXPelsPerMeter); //x축의 미터당 픽셀갯수
		//printf("biYPelsPerMeter %d\n", infoHeader.biYPelsPerMeter); //y축의 미터당 픽셀갯수

		//printf("biClrUsed %d\n", infoHeader.biClrUsed);           //이미지에서 사용된 color 갯수
		//printf("biClrImportant %d\n", infoHeader.biClrImportant); //이미지의 주요 color 갯수

		//이미지 형식 확인하기
		if (fileHeader.bfType == 0x4d42 && infoHeader.biBitCount == 32 && infoHeader.biClrImportant == 0)
		{
			//픽셀데이타 로드하기
			int length = width * height;    //로드할 이미지크기만큼의 메모리 
			data = new unsigned int[length];//로드공간 동적할당
			
			//x, y 에서 width, height 사각형 영역의 이미지만..로드하기///
			//fseek 사용하기
			int offset = (infoHeader.biWidth * y + x) * 4;
			fseek(stream, offset, SEEK_CUR);

			//사각형 이미지 로드하기
			int hGap = (infoHeader.biWidth - width) * 4;

			for (int i = 0; i < height; i++)
			{
				fread(data + i*width , sizeof(unsigned int), width, stream);
				fseek(stream, hGap, SEEK_CUR);
			}

			//파일닫기
			fclose(stream);

			//이미지구조체에..필요정보 저장하기
			image->width  = width;
			image->height = height;
			image->data   = data;

			return true;
		}
		else {

			printf("잘못된 비트맵 파일 형식임\n");
			return false;
		}
	}
	else {
		printf("파일 열기 실패\n");
		return false;
	}

}

void drawBMP(float px, float py, Image* image)
{
	//이미지 그리기(infoHeader.biWidth, infoHeader.biHeight, data)
	for (int y = 0; y < image->height; y++)
	{
		for (int x = 0; x < image->width; x++)
		{
			//setPixel로 x, y 좌표에 data배열의 픽셀을 출력
			unsigned int pixel = image->data[y * image->width + x];

			setPixel(px + x, py + y, pixel);
		}
	}
}

void drawBMP(float px, float py, Image* image, float fillAmount)
{
	//이미지 그리기(infoHeader.biWidth, infoHeader.biHeight, data)
	for (int y = 0; y < image->height; y++)
	{
		for (int x = 0; x < image->width * fillAmount; x++)
		{
			//setPixel로 x, y 좌표에 data배열의 픽셀을 출력
			unsigned int pixel = image->data[y * image->width + x];

			setPixel(px + x, py + y, pixel);
		}
	}
}
#pragma once

// freetype Çì´õ
#include <ft2build.h>
#include FT_FREETYPE_H

#include "GameObject.h"

class Text : public GameObject
{
private:
	FT_Library library;
	FT_Face    face;

public:
	Text(float px, float py);
	virtual ~Text();

	virtual void start();
	virtual void update();
	virtual void draw();
};
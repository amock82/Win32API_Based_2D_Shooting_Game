#pragma once

#include "Button.h"

class BTNPause : public Button
{
private:
	//bool isPause;

public:
	BTNPause(float px, float py);
	virtual ~BTNPause();

	virtual void start();
	virtual void onClick();
};
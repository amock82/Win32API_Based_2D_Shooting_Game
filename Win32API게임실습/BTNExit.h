#pragma once

#include "Button.h"

class BTNExit : public Button
{
private:

public:
	BTNExit(float px, float py);
	virtual ~BTNExit();

	virtual void start();
	virtual void onClick();
};
#include "framework.h"

bool Application::isPlaying = true;

void Application::quit()
{
	isPlaying = false;
}
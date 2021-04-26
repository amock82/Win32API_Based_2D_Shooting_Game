#pragma once

class Scene
{
private:

public:
	Scene();
	virtual ~Scene();

	virtual void load();
	virtual void run();
};
#pragma once
#include <vector>
#include "Scene.h"

class SceneFlee : public Scene
{
public:
	SceneFlee();
	~SceneFlee();
	void update(float dtime, SDL_Event *event);
	void draw();
	const char* getTitle();
private:
};


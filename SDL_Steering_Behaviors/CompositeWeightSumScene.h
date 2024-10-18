#pragma once
#include <vector>
#include "Scene.h"

class CompositeWeightSumScene : public Scene
{
public:
	CompositeWeightSumScene();
	~CompositeWeightSumScene();
	void update(float dtime, SDL_Event* event);
	void draw();
	const char* getTitle();
private:
};


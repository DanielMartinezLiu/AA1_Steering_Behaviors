#pragma once
#include <vector>
#include "Scene.h"

class CompositeWeightSumScene : public Scene
{
private:

public:
	CompositeWeightSumScene();
	~CompositeWeightSumScene();

	void update(float dtime, SDL_Event* event);
	void draw();
	const char* getTitle();

	void CreateAgents(int quantity, Vector2D position, Vector2D target);
};


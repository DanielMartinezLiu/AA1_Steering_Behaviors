#pragma once
#include <vector>
#include "Scene.h"

class PriorityListScene : public Scene
{
private:

public:
	PriorityListScene();
	~PriorityListScene();

	void update(float dtime, SDL_Event* event);
	void draw();
	const char* getTitle();

	void CreateAgents(int quantity, Vector2D position, Vector2D target);

};


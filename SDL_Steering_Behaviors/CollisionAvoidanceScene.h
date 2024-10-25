#pragma once
#include <vector>
#include "Scene.h"

class CollisionAvoidanceScene : public Scene
{
private:

public:
	CollisionAvoidanceScene();
	~CollisionAvoidanceScene();

	void update(float dtime, SDL_Event* event);
	void draw();
	const char* getTitle();

	void CreateAgents(int quantity, Vector2D position, Vector2D target);

};


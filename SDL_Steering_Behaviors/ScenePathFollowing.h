#pragma once
#include <cmath>
#include <vector>
#include "Scene.h"
#include "Agent.h"

class ScenePathFollowing : public Scene
{
private:
	std::vector<Agent*> agents;
	std::vector<Vector2D> targets;
	
	float CalculateDistance(Agent* agent);

public:
	ScenePathFollowing();
	~ScenePathFollowing();
	void update(float dtime, SDL_Event* event);
	void draw();
	const char* getTitle();
	
};
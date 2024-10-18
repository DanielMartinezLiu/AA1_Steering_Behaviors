#pragma once
#include "Agent.h"

#include <iostream>
#include <SDL.h>


class Scene
{
protected: 

	std::vector<Agent*> agents;
	Vector2D target;

public:
	Scene() {};
	virtual ~Scene() {};
	virtual void update(float dtime, SDL_Event *event) = 0;
	virtual void draw() = 0;
	virtual const char* getTitle() { return ""; };

	std::vector<Agent*> GetAgents() { return agents; }
};
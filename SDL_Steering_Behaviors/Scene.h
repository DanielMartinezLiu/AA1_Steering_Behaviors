#pragma once
#include <iostream>
#include <SDL.h>
#include "Agent.h"
#include <vector>

class Scene
{
private:
	
	std::vector<Agent*> agents;


public:
	Scene() {};
	virtual ~Scene() {};
	virtual void update(float dtime, SDL_Event *event) = 0;
	virtual void draw() = 0;
	virtual const char* getTitle() { return ""; };
};


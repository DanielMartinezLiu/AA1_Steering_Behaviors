#pragma once
#include <vector>

#include "Scene.h"
#include "Agent.h"

class SceneSeek : public Scene
{
private:
	std::vector<Agent*> agents;
	Vector2D target;

public:
	SceneSeek();
	~SceneSeek();
	void update(float dtime, SDL_Event *event) override;
	void draw() override;
	const char* getTitle();

};


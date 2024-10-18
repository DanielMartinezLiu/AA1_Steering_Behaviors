#pragma once
#include <vector>

#include "Scene.h"

class SceneSeek : public Scene
{
public:
	SceneSeek();
	~SceneSeek();
	void update(float dtime, SDL_Event *event) override;
	void draw() override;
	const char* getTitle();
};


#pragma once
#include <iostream>
#include <vector>
#include <minmax.h>
#include <SDL.h>
#include <SDL_image.h>

#include "utils.h"
#include "Vector2D.h"

class Obstacle
{
private:
	Vector2D position;
	float radius;

	SDL_Color color;

public:
	Obstacle(Vector2D _position);

	~Obstacle();
	void draw();
	Vector2D GetPosition() { return position; }
	float GetRadius() { return radius; }
};



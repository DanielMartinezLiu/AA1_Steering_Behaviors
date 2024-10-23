#pragma once
class Obstacle
{

};

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

	SDL_Color color;

	SDL_Texture* sprite_texture;
	bool draw_sprite;
	int sprite_num_frames;
	int sprite_w;
	int sprite_h;

public:
	Obstacle();

	~Obstacle();
	Vector2D getPosition();
	void setPosition(Vector2D position);
	void setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	void update(float dtime, SDL_Event* event);
	void draw();
	bool loadSpriteTexture(char* filename, int num_frames = 1);
};



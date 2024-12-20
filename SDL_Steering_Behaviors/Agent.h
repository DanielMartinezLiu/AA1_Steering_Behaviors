#pragma once
#include <iostream>
#include <vector>
#include <minmax.h>
#include <SDL.h>
#include <SDL_image.h>

#include "utils.h"
#include "Vector2D.h"
#include "ObstacleManager.h"
#include "Obstacle.h"

class Agent
{
	friend class SteeringBehavior;

private:
	SteeringBehavior* steering_behavior;
	Vector2D position;
	Vector2D velocity;
	Vector2D target;

	int currentTargetIndex;

	float mass;
	float orientation;
	float max_force;
	float max_velocity;
	float neighborRadius;
	float avoidanceLookahead;

	SDL_Color color;

	SDL_Texture *sprite_texture;
	bool draw_sprite;
	int sprite_num_frames;
	int sprite_w;
	int sprite_h;

public:
	Agent();
	Agent(SteeringBehavior* _steering_behavior, float _neighborRadius);

	~Agent();
	SteeringBehavior *GetSteeringBehavior();
	Vector2D getPosition();
	Vector2D getTarget();
	Vector2D getVelocity();
	int getCurrentTargetIndex();
	float getMaxForce();
	float getMaxVelocity();
	float getNeighborRadius();
	void setPosition(Vector2D position);
	void setTarget(Vector2D target);
	void setVelocity(Vector2D velocity);
	void addCurrentTargetIndex();
	void setMass(float mass);
	void setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	void update(float dtime, SDL_Event *event);
	void collisionEnter();
	bool obstacleIntersection(Obstacle* _obstacle, Vector2D &_raycast, Vector2D &_intersectionPoint, Vector2D &_normalVecotr);
	void draw();
	bool loadSpriteTexture(char* filename, int num_frames=1);
};

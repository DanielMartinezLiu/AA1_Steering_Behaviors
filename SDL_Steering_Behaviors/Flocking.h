#pragma once

#include "SteeringBehavior.h"

class Flocking : public SteeringBehavior
{
private:
	Vector2D targetPosition;

public:
	Flocking() = default;
	~Flocking();

	void ApplySteeringForce(Agent* agent, float dTime) override;

};


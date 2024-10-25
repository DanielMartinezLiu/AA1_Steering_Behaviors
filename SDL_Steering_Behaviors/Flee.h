#pragma once

#include "SteeringBehavior.h"

class Flee : public SteeringBehavior
{
public:
	Flee() = default;
	Flee(Vector2D target);

	~Flee();

	void ApplySteeringForce(Agent* agent, float dTime) override;

};


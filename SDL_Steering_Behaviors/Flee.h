#pragma once

#include "SteeringBehavior.h"

class Flee : public SteeringBehavior
{
private:
	Vector2D targetPosition;

public:
	Flee() = default;
	~Flee();

	void ApplySteeringForce(Agent* agent, float dTime) override;

};


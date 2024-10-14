#pragma once

#include "SteeringBehavior.h"

class Seek : public SteeringBehavior
{
private:
	Vector2D targetPosition;

public:
	Seek() = default;
	~Seek();

	void ApplySteeringForce(Agent* agent, float dTime) override;

};


#pragma once

#include "SteeringBehavior.h"

class Seek : public SteeringBehavior
{
public:
	Seek() = default;
	Seek(Vector2D target);

	~Seek();

	void ApplySteeringForce(Agent* agent, float dTime) override;

};


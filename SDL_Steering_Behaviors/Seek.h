#pragma once

#include "SteeringBehavior.h"

class Seek : public SteeringBehavior
{
public:
	Seek() = default;

	~Seek();

	void ApplySteeringForce(Agent* agent, float dTime) override;

};
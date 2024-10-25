#pragma once

#include "SteeringBehavior.h"

class PathFollowing : public SteeringBehavior
{
public:
	PathFollowing() = default;

	~PathFollowing();

	void ApplySteeringForce(Agent* agent, float dTime) override;
};


#pragma once

#include "SteeringBehavior.h"

class PathFollowing : public SteeringBehavior
{
private:
	Vector2D targetPosition;

public:
	PathFollowing() = default;
	~PathFollowing();

	void ApplySteeringForce(Agent* agent, float dTime) override;
};


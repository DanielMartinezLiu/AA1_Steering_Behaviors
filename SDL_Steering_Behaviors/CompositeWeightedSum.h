#pragma once
#include <vector>

#include "SteeringBehavior.h"

class CompositeWeightedSum : public SteeringBehavior
{
private:
	Vector2D targetPosition;

	std::vector<std::pair<SteeringBehavior*, float>> steerings;

public:
	CompositeWeightedSum() = default;
	~CompositeWeightedSum();

	void ApplySteeringForce(Agent* agent, float dTime) override;

};


#pragma once
#include <vector>
#include "SteeringBehavior.h"


class PriorityList : public SteeringBehavior
{
private:
	Vector2D targetPosition;

	std::vector<std::pair<SteeringBehavior*, float>> steerings;

public:
	PriorityList() = default;
	~PriorityList();

	void ApplySteeringForce(Agent* agent, float dTime) override;

	void AddSteeringBehavior(SteeringBehavior* steeringBehavior, float weight);
};





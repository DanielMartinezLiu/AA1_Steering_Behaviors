#pragma once
#include <vector>
#include "SteeringBehavior.h"


class PriorityList : public SteeringBehavior
{
private:
	Vector2D targetPosition;
	float K_PRIORITY_THRESHOLD;

	std::vector<SteeringBehavior*> steerings;

public:
	PriorityList() = default;
	PriorityList(float _threshold)
		: K_PRIORITY_THRESHOLD(_threshold) {};
	~PriorityList();

	void ApplySteeringForce(Agent* agent, float dTime) override;

	void PriorityList::AddSteeringBehavior(SteeringBehavior* _steeringBehavior);
};





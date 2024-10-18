#pragma once
#include "SteeringBehavior.h"

class Cohesion : public SteeringBehavior
{
private:
	int neighborCount;
	Vector2D averagePosition;

public:
	void ApplySteeringForce(Agent* _agent, float _dTime) override;

};


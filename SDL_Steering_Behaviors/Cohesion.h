#pragma once
#include "SteeringBehavior.h"

class Cohesion : public SteeringBehavior
{
public:
	void ApplySteeringForce(Agent* _agent, float _dTime) override;

};


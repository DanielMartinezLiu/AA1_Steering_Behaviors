#pragma once
#include "SteeringBehavior.h"

class Seek : public SteeringBehavior
{
public:
	void virtual ApplySteeringForce(Agent* _agent, float _dt) override;
};


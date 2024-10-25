#pragma once
#include "SteeringBehavior.h"

class Aligment : public SteeringBehavior
{
public:
	void ApplySteeringForce(Agent* _agent, float _dTime) override;

};

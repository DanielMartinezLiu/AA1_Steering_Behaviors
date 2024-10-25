#pragma once
#include "SteeringBehavior.h"
class Separation : public SteeringBehavior
{
public:

	void ApplySteeringForce(Agent* agent, float dTime) override;

};


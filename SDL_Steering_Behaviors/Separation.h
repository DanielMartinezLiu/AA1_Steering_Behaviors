#pragma once
#include "SteeringBehavior.h"
class Separation : public SteeringBehavior
{
private:

	int neighborCount;
	Vector2D separationVector;

public:

	void ApplySteeringForce(Agent* agent, float dTime) override;

};


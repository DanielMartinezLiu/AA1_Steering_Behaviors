#pragma once
#include "SteeringBehavior.h"
class Separation : public SteeringBehavior
{
private:

	int neighborCount;
	float neighborRadius;
	Vector2D separationVector;

public:

	void ApplySteeringForce(Agent* agent, float dTime) override;

};


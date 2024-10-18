#pragma once
#include "SteeringBehavior.h"

class Aligment : public SteeringBehavior
{
private:

	int neighborCount;
	Vector2D aligmentvelocity;

public:

	void ApplySteeringForce(Agent* _agent, float _dTime) override;

};

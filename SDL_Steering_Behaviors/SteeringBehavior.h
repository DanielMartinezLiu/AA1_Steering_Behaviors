#pragma once

#include "Vector2D.h"
#include "Agent.h"

class SteeringBehavior
{
protected:
	Vector2D targetPosition;
	Vector2D force;

public:
	SteeringBehavior();
	~SteeringBehavior();

	void virtual ApplySteeringForce(Agent* agent, float dTime) = 0;

	inline void SetTarget(Vector2D _targetPosition)
	{
		targetPosition = _targetPosition;
	}

	inline Vector2D GetForce() 
	{
		return force;
	}

	/*
	Vector2D Seek(Agent *agent, Vector2D target, float dtime);
	Vector2D Seek(Agent *agent, Agent *target, float dtime);
	Vector2D Flee(Agent *agent, Vector2D target, float dtime);
	Vector2D Flee(Agent *agent, Agent *target, float dtime);
	*/
};

#include "Flee.h"

Flee::~Flee()
{
}

void Flee::ApplySteeringForce(Agent* agent, float dTime)
{
	Vector2D direction = agent->getPosition() - targetPosition;
	direction.Normalize();
	direction *= agent->getMaxVelocity();
	force = direction - agent->getVelocity();
	force /= agent->getMaxVelocity();
	force *= agent->getMaxForce();
}

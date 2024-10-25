#include "Seek.h"

Seek::~Seek()
{
}

void Seek::ApplySteeringForce(Agent* agent, float dTime)
{
	Vector2D direction = targetPosition - agent->getPosition();
	direction.Normalize();
	direction *= agent->getMaxVelocity();
	force = direction - agent->getVelocity();
	force /= agent->getMaxVelocity();
	force *= agent->getMaxForce();
}

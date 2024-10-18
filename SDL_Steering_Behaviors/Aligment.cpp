#include "Aligment.h"
#include "AgentManager.h"

void Aligment::ApplySteeringForce(Agent* _agent, float _dTime)
{
	for (Agent* agent : AM.Instance().GetAgents())
	{
		if (Vector2D::Distance(agent->getPosition(), _agent->getPosition()) < _agent->getNeighborRadius())
		{
			aligmentvelocity += agent->getVelocity();
			++neighborCount;
		}
	}

	aligmentvelocity /= neighborCount;
	force = aligmentvelocity.Normalize();
}

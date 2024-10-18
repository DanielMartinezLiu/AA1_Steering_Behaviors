#include "Cohesion.h"
#include "AgentManager.h"

void Cohesion::ApplySteeringForce(Agent* _agent, float _dTime)
{
	for (Agent* agent : AM.Instance().GetAgents())
	{
		if (agent != _agent)
		{
			if (Vector2D::Distance(agent->getPosition(), _agent->getPosition()) < _agent->getNeighborRadius())
			{
				averagePosition += agent->getPosition();
				++neighborCount;
			}
		}
	}

	if (neighborCount == 0)
	{
		force = 0;
		return;
	}

	averagePosition /= neighborCount;
	averagePosition -= _agent->getPosition();
	force = averagePosition.Normalize();

}

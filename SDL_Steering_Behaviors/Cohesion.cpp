#include "Cohesion.h"
#include "AgentManager.h"

void Cohesion::ApplySteeringForce(Agent* _agent, float _dTime)
{
	for (Agent* agent : AM.Instance().GetAgents())
	{
		if (Vector2D::Distance(agent->getPosition(), _agent->getPosition()) < neighborRadius)
		{
			averagePosition += agent->getPosition();
			++neighborCount;
		}
	}

	averagePosition /= neighborCount;
	averagePosition -= _agent->getPosition();
	force = averagePosition.Normalize();
}

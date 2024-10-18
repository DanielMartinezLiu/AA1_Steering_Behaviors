#include "Separation.h"
#include "AgentManager.h"

void Separation::ApplySteeringForce(Agent* _agent, float _dTime)
{
	int neighborCount = 0;
	Vector2D separationVector;

	for (Agent* agent : AM.Instance().GetAgents())
	{
		if (agent != _agent)
		{
			if (Vector2D::Distance(agent->getPosition(), _agent->getPosition()) < _agent->getNeighborRadius())
			{
				separationVector += _agent->getPosition() - agent->getPosition();
				++neighborCount;
			}
		}
	}

	if (neighborCount == 0)
	{
		force = 0;
		return;
	}

	separationVector /= neighborCount;
	force = separationVector.Normalize(); 
}

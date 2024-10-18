#include "Separation.h"
#include "AgentManager.h"

void Separation::ApplySteeringForce(Agent* _agent, float _dTime)
{
	for (Agent* agent : AM.Instance().GetAgents())
	{
		if (Vector2D::Distance(agent->getPosition(), _agent->getPosition()) < neighborRadius)
		{
			separationVector += _agent->getPosition() - _agent->getPosition();
			++neighborCount;
		}
	}

	separationVector /= neighborCount;
	force = separationVector.Normalize(); 
}

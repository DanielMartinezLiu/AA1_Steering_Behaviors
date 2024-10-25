#include "PriorityList.h"

PriorityList::~PriorityList()
{
}

void PriorityList::ApplySteeringForce(Agent* agent, float dTime)
 {
	for (SteeringBehavior* steeringBehavior : steerings)
	{
		steeringBehavior->SetTarget(agent->getTarget());
		steeringBehavior->ApplySteeringForce(agent, dTime);

		std::cout << steeringBehavior->GetForce().Length() << std::endl;
			force += steeringBehavior->GetForce();
		if (steeringBehavior->GetForce().Length() > K_PRIORITY_THRESHOLD)
		{
			return;
		}
	}
}

void PriorityList::AddSteeringBehavior(SteeringBehavior* _steeringBehavior)
{
	steerings.push_back(_steeringBehavior);
}

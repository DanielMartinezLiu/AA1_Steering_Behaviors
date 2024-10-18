#include "PriorityList.h"

PriorityList::~PriorityList()
{
}

void PriorityList::ApplySteeringForce(Agent* agent, float dTime)
{
	for (std::pair<SteeringBehavior*, float> pair : steerings)
	{
		force = pair.first->GetForce();
		if (force.Length() > K_PRIORITY_THRESHOLD)
		{
			return;
		}
	}
}

void PriorityList::AddSteeringBehavior(SteeringBehavior* steeringBehavior, float weight)
{
	std::pair<SteeringBehavior*, float> newPair;
	newPair.first = steeringBehavior;
	newPair.second = weight;
	steerings.push_back(newPair); 
}

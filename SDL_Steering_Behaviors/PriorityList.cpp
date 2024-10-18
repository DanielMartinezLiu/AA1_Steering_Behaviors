#include "PriorityList.h"

PriorityList::~PriorityList()
{
}

void PriorityList::ApplySteeringForce(Agent* agent, float dTime)
{

}

void PriorityList::AddSteeringBehavior(SteeringBehavior* steeringBehavior, float weight)
{
	std::pair<SteeringBehavior*, float> newPair;
	newPair.first = steeringBehavior;
	newPair.second = weight;
	steerings.push_back(newPair); 
}

#include "CompositeWeightedSum.h"

CompositeWeightedSum::~CompositeWeightedSum()
{
	for (int i = 0; i < steerings.size(); i++)
	{
		delete steerings[i].first;
	}
}

void CompositeWeightedSum::ApplySteeringForce(Agent* agent, float dTime)
{
	for (std::pair<SteeringBehavior*, float> pair : steerings)
	{
		pair.first->SetTarget(agent->getTarget());
		pair.first->ApplySteeringForce(agent, dTime);
		force += pair.first->GetForce() * pair.second;
	}
}

void CompositeWeightedSum::AddSteeringBehavior(SteeringBehavior* steeringBehavior, float weight)
{
	std::pair<SteeringBehavior*, float> newPair;
	newPair.first = steeringBehavior;
	newPair.second = weight;
	steerings.push_back(newPair);
}

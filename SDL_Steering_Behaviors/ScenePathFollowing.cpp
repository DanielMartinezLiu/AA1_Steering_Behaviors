#include "ScenePathFollowing.h"
#include "CompositeWeightedSum.h"

ScenePathFollowing::ScenePathFollowing()
{
	Agent* agent = new Agent(new CompositeWeightedSum());
	agent->GetSteeringBehavior();
	agent->setPosition(Vector2D(640, 360));
	agent->setTarget(Vector2D(640, 360));
	agent->loadSpriteTexture("../res/soldier.png", 4);
	agents.push_back(agent);
}

ScenePathFollowing::~ScenePathFollowing()
{
	for (int i = 0; i < (int)agents.size(); i++)
	{
		delete agents[i];
	}
}

void ScenePathFollowing::update(float dtime, SDL_Event* event)
{
	/* Keyboard & Mouse events */
	switch (event->type) {
	case SDL_MOUSEMOTION:
	case SDL_MOUSEBUTTONDOWN:
		if (event->button.button == SDL_BUTTON_LEFT)
		{
			targets.push_back(Vector2D((float)(event->button.x), (float)(event->button.y)));
			
			if (targets.size() <= 1)
				agents[0]->setTarget(targets[0]);

			std::cout << CalculateDistance(agents[0]) << std::endl;
		}
		break;
	default:
		break;
	}

	if (targets.size() > 0)
	{
		if (CalculateDistance(agents[0]) < 100 && agents[0]->getCurrentTargetIndex() + 1 < targets.size())
		{

			agents[0]->addCurrentTargetIndex();
			agents[0]->setTarget(targets[agents[0]->getCurrentTargetIndex()]);
		}
	}
	
	agents[0]->update(dtime, event);
}

void ScenePathFollowing::draw()
{
	for (Vector2D target : targets)
	{
		draw_circle(TheApp::Instance()->getRenderer(), (int)target.x, (int)target.y, 15, 255, 0, 0, 255);
	}
	agents[0]->draw();
}

const char* ScenePathFollowing::getTitle()
{
	return "SDL Steering Behaviors :: Path Following Demo";
}

float ScenePathFollowing::CalculateDistance(Agent* agent)
{
	float result =
		sqrt(
			pow((targets[agent->getCurrentTargetIndex()] - agent->getPosition()).x, 2) + 
			pow((targets[agent->getCurrentTargetIndex()] - agent->getPosition()).y, 2)
		);
	return result;
}
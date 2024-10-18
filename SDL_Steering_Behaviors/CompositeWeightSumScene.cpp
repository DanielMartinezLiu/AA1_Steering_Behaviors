#include "CompositeWeightSumScene.h"
#include "CompositeWeightedSum.h"
#include "Seek.h"
#include "Separation.h"
#include "Aligment.h"
#include "Cohesion.h"

#include "SDL_SimpleApp.h"
#include "AgentManager.h"

using namespace std;

CompositeWeightSumScene::CompositeWeightSumScene()
{
	CompositeWeightedSum* compositedWeightSum = new CompositeWeightedSum();
	compositedWeightSum->AddSteeringBehavior(new Seek(), 1.f);
	compositedWeightSum->AddSteeringBehavior(new Cohesion(), 0.5f);
	compositedWeightSum->AddSteeringBehavior(new Separation(), 0.8f);
	compositedWeightSum->AddSteeringBehavior(new Aligment(), 0.2f);
	Agent* agent = new Agent(compositedWeightSum, 50);
	Agent* agent2 = new Agent(compositedWeightSum, 50);

	agent->setPosition(Vector2D(640, 360));
	agent->setTarget(Vector2D(640, 360));
	agent->loadSpriteTexture("../res/soldier.png", 4);
	agents.push_back(agent);
	agent2->setPosition(Vector2D(140, 360));
	agent2->setTarget(Vector2D(640, 360));
	agent2->loadSpriteTexture("../res/soldier.png", 4);
	agents.push_back(agent2);
	target = Vector2D(640, 360);

	AM.Instance().SetAgents(GetAgents());
}

CompositeWeightSumScene::~CompositeWeightSumScene()
{
	for (int i = 0; i < (int)agents.size(); i++)
	{
		delete agents[i];
	}
}

void CompositeWeightSumScene::update(float dtime, SDL_Event* event)
{
	/* Keyboard & Mouse events */
	switch (event->type) {
	case SDL_MOUSEMOTION:
	case SDL_MOUSEBUTTONDOWN:
		if (event->button.button == SDL_BUTTON_LEFT)
		{
			target = Vector2D((float)(event->button.x), (float)(event->button.y));
			for (int i = 0; i < (int)agents.size(); i++)
				agents[i]->setTarget(target);
		}
		break;
	default:
		break;
	}
	for (int i = 0; i < (int)agents.size(); i++)
		agents[i]->update(dtime, event);
}

void CompositeWeightSumScene::draw()
{
	draw_circle(TheApp::Instance()->getRenderer(), (int)target.x, (int)target.y, 15, 255, 0, 0, 255);
	for (int i = 0; i < (int)agents.size(); i++)
		agents[i]->draw();
}

const char* CompositeWeightSumScene::getTitle()
{
	return "SDL Steering Behaviors :: CompositeWheightSum Demo";
}
